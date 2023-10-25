#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


#define MAXFIL 10
#define MAXCOL 10

typedef struct
{
    int x;
    int y;
    int valor;
}tSnake;


int leerMatriz(char* nomArch, int mat[MAXFIL][MAXCOL], int* fil, int* col);
void mostrarMatrizTablero(int mat[MAXFIL][MAXCOL], int fil, int col);
int LazySnakeGame(char* nomArch);
void recorrerTablero(int mat[MAXFIL][MAXCOL], int fil,int col);
#endif // SNAKE_H_INCLUDED
