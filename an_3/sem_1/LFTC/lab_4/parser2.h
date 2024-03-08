#pragma once


bool program();
void tkerr(const char* fmt, ...);
bool consume(int code);
bool defVar();
bool baseType();


// parse the extracted tokens
void parse();