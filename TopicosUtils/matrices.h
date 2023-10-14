#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXCOL 100
typedef int Cmp(const void*, const void*);

void recorrerMatriz(void** mat,unsigned cf,unsigned cc,size_t tam, void accion(const void* elem));
void** crearMatrizDinamica(unsigned cf, unsigned cc, size_t tam);
void destruirMatriz(void** matriz, unsigned filas);

#endif // MATRICES_H_INCLUDED
