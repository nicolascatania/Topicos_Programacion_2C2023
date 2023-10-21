#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//modificar estos define en función de los archivos de texto a leer
#define CANTCAMPOS 5
#define MAXCOL 50
#define DNI "dni"
#define LEGAJO "legajo"
#define PROMEDIO "promedio"
#define EDAD "edad"
#define GENERO "genero"

typedef struct
{
    int dni;
    int legajo;
    float promedio;
    int edad;
    char genero;
}tAlumno;

void aluABIN(const char* nomArch, const char* modo, const char* ArchivoDestino);
int leerCampos(char mat[CANTCAMPOS][MAXCOL], FILE* pf);
void prepararAlu(char mat[CANTCAMPOS][MAXCOL],int* indices, tAlumno* alu);
void obtenerIndices(char mat[CANTCAMPOS][MAXCOL], int* indices, char* campo);
#endif // ALUMNOS_H_INCLUDED
