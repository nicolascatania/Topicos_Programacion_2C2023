#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef int Cmp(const void*, const void*);

void insertarEnVectorOrdenado(void* vec,int* ce,size_t tam, void* elem, Cmp cmp);
void* crearVectorDinamico(unsigned n, size_t tam);
void recorrerVector(void* vec,int ce,size_t tam,void accion(void*));
void* buscarMenor(void* vec,int ce,size_t tam,int cmp(const void*a, const void* b));
void ordenarSeleccion(void* vec, int ce, size_t tam,Cmp cmp);
#endif // VECTORES_H_INCLUDED
