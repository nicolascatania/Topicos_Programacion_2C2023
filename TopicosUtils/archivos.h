#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int abrirArchivo(FILE** pf,char* nomArch, char* modo);
void mostrarArchivo(char* nomArch,char*modo, size_t tam,void accion(const void*));

#endif // ARCHIVOS_H_INCLUDED
