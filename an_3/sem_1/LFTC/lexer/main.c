#include <lexer.h>
#include <utils.h>

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    char* inbuff = loadFile("1.q");
    tokenize(inbuff);
    showTokens();
    free(inbuff);

    return 0;
}