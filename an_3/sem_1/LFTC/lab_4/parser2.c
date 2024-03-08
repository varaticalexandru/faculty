#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "lexer.h"
#include "parser2.h"

int iTk;	// the iterator in tokens
Token *consumed;	// the last consumed token

// same as err, but also prints the line of the current token
_Noreturn; void tkerr(const char* fmt, ...) {
	fprintf(stderr, "error in line %d: ", tokens[iTk].line);
	va_list va;
	va_start(va, fmt);
	vfprintf(stderr, fmt, va);
	va_end(va);
	fprintf(stderr, "\n");
	exit(EXIT_FAILURE);
}

void parse() {
	iTk = 0;
	program();
}


bool consume(int code){
	if(tokens[iTk].code==code){	// if the current token is of type code
		consumed=&tokens[iTk++];	// set consumed to the current token and increment iTk
		return true;
		}
	return false;
}	


// baseType ::= TYPE_INT | TYPE_REAL | TYPE_STR
bool baseType() {
	// memorize the current value of iTk
	int start_iTk = iTk;

	if (consume(TYPE_INT)) { return true; }
	else if (consume(TYPE_REAL)) { return true; }
	else if (consume(TYPE_STR)) { return true; }
	else {
		// restore iTk
		iTk = start_iTk;
		return false;
	}
}

// defVar ::= VAR ID COLON basetype SEMICOLON
bool defVar() {
	// memorize the current value of iTk
	int start_iTk = iTk;

	if (consume(VAR)) {
		if (consume(ID)) {
			if (consume(COLON)) {
				if (baseType()) {
					if (consume(SEMICOLON)) {
						return true;
					}
					else tkerr("syntax error: missing ';' after base type");
				}
				else tkerr("syntax error: missing base type after ':'");
			}
			else tkerr("syntax error: missing ':' after id");
		}
		else tkerr("syntax error: missing id after var");
	}
	else {
		// restore iTk
		iTk = start_iTk;
		return false;
	}
}

// program ::= ( defVar | defFunc | block )* FINISH
bool program(){
	for(;;){
		if(defVar()){}
		/*else if(defFunc()){}
		else if(block()){}*/
		else break;
		}
	if(consume(FINISH)){
		return false;
	}else tkerr("syntax error");
	return false;
}



// defFunc ::= FUNCTION ID LPAR funcParams? RPAR COLON basetype defVar* block END
