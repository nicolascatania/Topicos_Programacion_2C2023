#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int rstrlen(const char* cad);
void rstrcpy(char* destino,const char* origen);
char* rstrchr(const char* cad, const char c);
char* rstrrchr(const char* cad, char* c);
int resPalindromo(const char* cad);
int _resPalindromo(char* p1, char* p2);
char* rreverse(char* cad);
char* _rreverse(char* p1, char*p2);
#endif // MYSTRING_H_INCLUDED
