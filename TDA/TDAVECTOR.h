#ifndef TDAVECTOR_H_INCLUDED
#define TDAVECTOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINALLOC 10
#define ESPACIOEXTRA 5


typedef struct
{
    void* elem;
    size_t tamElem;
}tNodo;

typedef struct
{

    tNodo* vec;
    unsigned tam;
    unsigned ce;
}TDAVector;

int crearTDAVector(TDAVector* tdav);
int insertarEnTDA(TDAVector* tdav, void* elem, size_t tamElem);
void mostrarTDAVector(TDAVector* tdav, void accion(const void*));
void mostrarEntero(const void* elem);
int agregarMemoriaTDA(TDAVector* tdav);
void destruirTDAVector(TDAVector* tdav);


#endif // TDAVECTOR_H_INCLUDED
