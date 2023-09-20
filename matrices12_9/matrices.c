#include "matrices.h"


void mostrarMatriz(int mat[][TAM], int cf,int cc)
{
    int f,c;
    for(f=0; f<cf; f++)
    {
        for(c=0; c<cc; c++)
        {
            printf("%d",mat[f][c]);
        }
        printf("\n");
    }
}

int validarMatrizObtenerResultados(int mat[][TAM],int n, int* vecResultados)
{
    int f,c;
    int cant_filas=n-1, cant_columnas=n-1;
    for(f=0; f<cant_filas; f++)
    {
        for(c=f+1; c<=cant_columnas; c++)
        {
            if(!validaPosicion(mat,f,c))
            {
                return 0;
            }
            else
            {
                //sumo al vecResultados y voy acumulando la suma de puntos
                *(vecResultados+f)+=mat[f][c];
                *(vecResultados+c)+=mat[c][f];
            }
        }
    }
    return 1; //todo bien
}
int validaPosicion(int mat[][TAM], int f,int c)
{
    if((mat[f][c]==2 && mat[c][f]!=2)||(mat[f][c]==3 && mat[c][f]!=3)||(mat[f][c]==0 && mat[c][f]!=6)||(mat[f][c]==6 && mat[c][f]!=0)||(mat[f][c]==1 && mat[c][f]!=4)||(mat[f][c]==4 && mat[c][f]!=1))
    {
        return 0; //todo mal
    }
    return 1;
}

void mostrarVector(int* v,int largo)
{
    int i;
    for(i=0; i<largo; i++)
    {
        printf("%d ",*v);
        v++;
    }
    printf("\n");
}

void sumaDiagonalesMatriz(int mat[][TAM],int n, int* vecResultado)
{


    int f;
    *vecResultado=0;
    *(vecResultado+1)=0;
    for(f=0; f<n; f++)
    {
        *vecResultado+=mat[f][f];
        *(vecResultado+1)+=mat[f][n-1-f];
    }


}

int ejercicio112(int mat[][TAM],int n, int* vecResultados)
{

    // vecResultados[8]={suma Triangulo superior sin diagonal, suma triangulo inferior sin diagonal, suma triangulo superior con diagonal, suma triangulo inferior con diagonal principal
    //suma triangulo superior diag secu, suma triangulo inferior diag secu, suma triangulo sup diag secu incluida, suma triangulo inf diag secu incluida}

    sumaTrianguloSuperioreInferiorPrincipal(mat,n,vecResultados);
    sumaTrianguloSuperioreInferiorSecundario(mat,n,vecResultados);

}

void sumaTrianguloSuperioreInferiorPrincipal(int mat[][TAM], int n, int* vecResultados)
{
    int vecSumaDiagonal[2];
    sumaDiagonalesMatriz(mat,n,vecSumaDiagonal);

    for (int f = 0; f < n; f++)
    {
        for (int c = f + 1; c < n; c++)
        {
            // Triángulo superior con diagonal
            *vecResultados += mat[f][c];
            // Triángulo inferior con diagonal
            *(vecResultados+1) += mat[c][f];
            // Triángulo superior con diagonal principal
            *(vecResultados+2) += mat[f][c];
            // Triángulo inferior con diagonal principal
            *(vecResultados+3) += mat[c][f];
        }
    }

    *(vecResultados+2)+=*vecSumaDiagonal;
    *(vecResultados+3)+=*vecSumaDiagonal;

}

void sumaTrianguloSuperioreInferiorSecundario(int mat[][TAM], int n, int* vecResultados)
{
    int vecSumaDiagonal[2];
    sumaDiagonalesMatriz(mat,n,vecSumaDiagonal);
    for (int f = 0; f < n; f++)
    {
        for (int c = 0; c < n - 1 - f; c++)
        {
            // Triángulo superior sin diagonal secundaria
            *(vecResultados+4) += mat[f][c];
            // Triángulo inferior sin diagonal secundaria
            *(vecResultados+5) += mat[n - 1 - c][n - 1 - f];
            // Triángulo superior con diagonal secundaria incluida
            *(vecResultados+6) += mat[f][c];
            // Triángulo inferior con diagonal secundaria incluida
            *(vecResultados+7) += mat[n - 1 - c][n - 1 - f];
        }
    }
    *(vecResultados+6)+=*(vecSumaDiagonal+1);
    *(vecResultados+7)+=*(vecSumaDiagonal+1);

}

int esMatrizDiagonal(int mat[][TAM],int n)
{
    int f,c;
    for(f=0; f<n; f++) //la idea acá es recorrer solo la mitad superior (diagonal incluida) ya que cn los indices puedo acceder a los valores d la otra mitad
    {
        if(mat[f][f]==0)
        {
            return 0; //no es diagonal
        }
        for(c=f+1; c<n; c++)
        {
            if((mat[f][c]!=0)||(mat[c][f]!=0))
            {
                return 0;//no es diagonal
            }
        }
    }

    return 1; //es diagonal, no presentó ningun problema durante el recorrido
}

int esMatrizIdentidad(int mat[][TAM],int n)
{
    int f,c;
    for(f=0; f<n; f++) //la idea acá es recorrer solo la mitad superior (diagonal incluida) ya que cn los indices puedo acceder a los valores d la otra mitad
    {
        if(mat[f][f]!=1)
        {
            return 0; //no es  identidad
        }
        for(c=f+1; c<n; c++)
        {
            if((mat[f][c]!=0)||(mat[c][f]!=0))
            {
                return 0;//no es identidad
            }
        }
    }

    return 1; //es identidad, no presentó ningun problema durante el recorrido
}

void multiplicarMatrices(int matriz1[][TAM], int fila1, int col1, int matriz2[][TAM], int fila2, int col2, int resultado[][TAM])
{
    for (int i = 0; i < fila1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            resultado[i][j] = 0;
            for (int k = 0; k < col1; k++)
            {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }
}


void recorrerMatrizCircular(int matriz[][TAM], int filas, int columnas)
{
    int inicioFila = 0;
    int finFila = filas - 1;
    int inicioColumna = 0;
    int finColumna = columnas - 1;
    int i;
    while (inicioFila <= finFila && inicioColumna <= finColumna)
    {
        // Imprimir la fila superior
        for ( i = inicioColumna; i <= finColumna; i++)
        {
            printf("%d ", matriz[inicioFila][i]);
        }
        inicioFila++;

        // Imprimir la columna derecha
        for ( i = inicioFila; i <= finFila; i++)
        {
            printf("%d ", matriz[i][finColumna]);
        }
        finColumna--;

        // Imprimir la fila inferior (si todavía es válida)
        if (inicioFila <= finFila)
        {
            for (i = finColumna; i >= inicioColumna; i--)
            {
                printf("%d ", matriz[finFila][i]);
            }
            finFila--;
        }

        // Imprimir la columna izquierda (si todavía es válida)
        if (inicioColumna <= finColumna)
        {
            for ( i = finFila; i >= inicioFila; i--)
            {
                printf("%d ", matriz[i][inicioColumna]);
            }
            inicioColumna++;
        }
    }
    printf("\n");

}

void trasponerMatriz(int mat[][TAM], int transpuesta[][TAM], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            transpuesta[j][i] = mat[i][j];
        }
    }
}

void trasponerMatrizCuadrada(int mat[][TAM], int filas, int columnas)
{

    int f, c, cc=columnas-1, cf=filas-1,aux;

    //si es cuadrada, la diagonal principal queda igual, solo me preocupo por cambiar los valores de las esquinas
    for(f=0; f<cf; f++)
    {
        for(c=f+1; c<=cc; c++)
        {
            aux= mat[c][f];
            mat[c][f]=mat[f][c];
            mat[f][c]=aux;
        }
    }


}
