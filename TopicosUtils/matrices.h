#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXCOL 100
typedef int Cmp(const void*, const void*);

void recorrerMatriz(void* matriz, int filas, int columnas, size_t tam, void (*accion)(const void* elem, const int columnas, const int col));
void** crearMatrizDinamica(unsigned cf, unsigned cc, size_t tam);
int** multiplicarMatricesEnteras(int* mat1, int* mat2, int cf1, int cc1, int cf2, int cc2);
void destruirMatriz(void** matriz, unsigned filas);

#endif // MATRICES_H_INCLUDED
