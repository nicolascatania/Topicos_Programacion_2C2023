#ifndef RECURSIVAS_H_INCLUDED
#define RECURSIVAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define A_MAYUS(x) ((x>='a' && x<='z')?(x-('a'-'A')):x)
#define ES_LETRA(x) (((x) >= 'A' && (x) <= 'Z') || ((x) >= 'a' && (x) <= 'z'))
unsigned long long factorial(int x);
int rstrlen(const char* cad);
void rstrcpy(char* destino,const char* origen);
char* rstrchr(const char* cad, const char c);
char* rstrrchr(const char* cad, char* c);
int resPalindromo(const char* cad);
int _resPalindromo(char* p1, char* p2);
char* rreverse(char* cad);
char* _rreverse(char* p1, char*p2);
#endif // RECURSIVAS_H_INCLUDED
