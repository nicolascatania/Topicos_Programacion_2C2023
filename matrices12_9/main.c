#include "matrices.h"

int main()
{
    int vecResultados[]= {0,0,0,0};
    int mat2[4][TAM]={{0,6,6,6},{0,0,2,1},{0,2,0,6},{0,4,0,0}};
    //ej 1.20
    mostrarMatriz(mat2,4,4);
    if(validarMatrizObtenerResultados(mat2,4, vecResultados)==0)
    {
        puts("Matriz invalida");
    }
    mostrarVector(vecResultados,4);
    //ej 1.12
    int vecResultados112[]={0,0,0,0,0,0,0,0};
    ejercicio112(mat2,4,vecResultados112);
    mostrarVector(vecResultados112,8);


    //ej 1.13
    int* sumaDiagonales[2];
    sumaDiagonalesMatriz(mat2,4,sumaDiagonales);
    mostrarVector(sumaDiagonales,2);

    //ej 1.14
    int matDiagonal[][TAM]={
    {1,0,0},
    {0,1,0},
    {0,0,1}};
    if(esMatrizDiagonal(matDiagonal,3))
    {
        puts("ES DIAGONAL");
    }
    else
    {
        puts("NO ES DIAGONAL");
    }

    //ej 1.15

    int matIdentidad[][TAM]={{1,0,0},{0,1,0},{0,0,1},};
    if(esMatrizIdentidad(matIdentidad,3))
    {
        puts("ES IDENTIDAD");
    }
    else
    {
        puts("NO ES IDENTIDAD");
    }

    //multiplicar
    int matR[][TAM]={{0}};
    int matx[][TAM]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int maty[][TAM]={{1,2,3},{4,5,6},{7,8,9}};
    int matz[][TAM]={{1,2,3},{4,5,6},{7,8,9}};
    multiplicarMatrices(matz,3,3,maty,3,3,matR);

    //recorrer matriz en circulos
    recorrerMatrizCircular(maty,3,3);

    //trasponer matriz in situ
    trasponerMatrizCuadrada(matx,3,3);
    mostrarMatriz(matx,3,3);


    return 0;
}
