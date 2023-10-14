#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED
#define MAXLENGHT 1024
#define CANTFRASES 5
#define LETRAS_ABECEDARIO 26
#define AMAYUS(c) ((c >= 'a' && c<= 'z') ? (c - 'a' + 'A') : c)
#define ESLETRA(c) ((c >= 'a' && c<= 'z')||(c >= 'A' && c<= 'Z'))
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct{

    int apariciones;
    char inicial;
}tInicial;


//variante 1
char* obtenerFrase(char* frase);
void obtener5FrasesMasLargasMatriz();
void insertarOrdenado2(char mat[][MAXLENGHT], char* frase,int fil,int*ce);


//variante 2
void obtenerNInicialesConMasApariciones(int cantidadIniciales);
void mostrarVectorIniciales(tInicial* vec, int* ce);
int cmpIniciales(const void*a, const void*b);
void insertarEnVectorOrdenado(void* vec, void* elem, int cmp(const void* a, const void*b),int tamVector, int* ce, size_t tam);
void llenarVectorIniciales(tInicial* vec);
void contarInicial(char* frase, tInicial* vecIniciales);
void setearResultado(tInicial* vec, int elementos);



//variante 3
void mostrarFrasesConPalabrasCoincidentes();
char** obtenerCoincidencias(char mat[][MAXLENGHT],const int ce);

int obtenerPalabra(char* frase, char* palabra, int* caracteresLeidos);
int buscarPalabra(const char *cadena, const char *palabra);
void destruirMatriz(void **matriz, int filas);
void **crearMatrizGenerica(int filas, int columnas, size_t tamanoElemento);
#endif // EXAMEN_H_INCLUDED
