#pragma once

enum{
	// identifiers
	ID = 0,

	// keywords
	VAR = 1,
	FUNCTION = 2,
	IF = 3,
	ELSE = 4,
	WHILE = 5,
	END = 6,
	RETURN = 7,
	TYPE_INT = 8,
	TYPE_REAL = 9,
	TYPE_STR = 10,

	// delimiters
	COMMA = 11,
	COLON = 12,
	SEMICOLON = 13,
	LPAR = 14,
	RPAR = 15,
	FINISH = 12,
	
	// operators
	ADD = 13,
	SUB = 14,
	MUL = 15,
	DIV = 16,
	AND = 17,
	OR = 18,
	NOT = 19,
	ASSIGN = 20,
	EQUAL = 21,
	NOTEQ = 22,
	LESS = 23,
	GREATER = 24,
	GREATEREQ = 25,

	// constants
	INT = 26,
	REAL = 27,
	STR = 28
	};

#define MAX_STR		127

typedef struct{
	int code;		// ID, TYPE_INT, ...
	int line;		// the line from the input file
	union{
		char text[MAX_STR+1];		// the chars for ID, STR
		int i;		// the value for INT
		double r;		// the value for REAL
		};
} Token;

#define MAX_TOKENS		4096
extern Token tokens[];
extern int nTokens;

void tokenize(const char *pch);
void showTokens();