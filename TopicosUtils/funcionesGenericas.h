#ifndef FUNCIONESGENERICAS_H_INCLUDED
#define FUNCIONESGENERICAS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef int Cmp(const void*, const void*);


void mostrarEntero(void* a);
void mostrarFloat(void* a);
int compararEntero(const void*a, const void*b);
int compararFloat(const void*a, const void*b);

//reduce
void acumularEnteros(const void* dato, void* res);
void acumularFloats(const void* dato, void*res);
void promedioEnterosReduce(const void* dato, void* res);
void promedioFloatsReduce(const void* dato, void* res);
void promedioDoubleReduce(const void* dato, void* res);
//filter
int filtrarEnterosMenoresA(const void* dato, void* parametro);
int filtrarEnterosMayoresA(const void* dato, void* parametro);
int filtrarEnterosIgualesA(const void* dato, void* parametro);
int filtrarFloatsMenoresA(const void* dato, void* parametro);
int filtrarFloatsMayoresA(const void* dato, void* parametro);
int filtrarFloatsIgualesA(const void* dato, void* parametro);


void intercambio(void*a, void*b,size_t tam);
void* busquedaBinaria(void* vec, void* clave, size_t tam, int ce, int cmp(const void*a, const void*b));
void reduce(const void* vec, int ce, size_t tam, void* resultado, void accion(const void* dato, void* res));
void filter(void* vec, int* ce, size_t tam, void* filtro(const void* dato,const void* parametro),void* parametro);
int rmap(void* vec, int ce, size_t tam, void accion(void*));

#endif // FUNCIONESGENERICAS_H_INCLUDED
