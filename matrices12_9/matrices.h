#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define TAM 50

void mostrarVector(int* v,int largo);
void mostrarMatriz(int mat[][TAM], int cf,int cc);
int validarMatrizObtenerResultados(int mat[][TAM],int n, int* vecResultados);
int validaPosicion(int mat[][TAM], int f,int c);
void sumaDiagonalesMatriz(int mat[][TAM],int n, int* vecResultado);
int ejercicio112(int mat[][TAM],int n, int* vecResultados);
void sumaTrianguloSuperioreInferiorSecundario(int mat[][TAM],int n, int* vecResultados);
void sumaTrianguloSuperioreInferiorPrincipal(int mat[][TAM],int n, int* vecResultados);
int esMatrizDiagonal(int mat[][TAM],int n);
void multiplicarMatrices(int matriz1[][TAM], int fila1, int col1, int matriz2[][TAM], int fila2, int col2, int resultado[][TAM]);
void trasponerMatriz(int mat[][TAM], int transpuesta[][TAM], int filas, int columnas);
void trasponerMatrizCuadrada(int mat[][TAM], int filas, int columnas);
#endif // MATRICES_H_INCLUDED
