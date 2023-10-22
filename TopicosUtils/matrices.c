#include "matrices.h"
#include "funcionesGenericas.h"


int** multiplicarMatricesEnteras(int* mat1, int* mat2, int cf1, int cc1, int cf2, int cc2)
{
    int i, j, k, suma;

    if (cc1 != cf2)
    {
        return NULL;  // Verificar si las matrices son multiplicables
    }

    int** matR = (int**)crearMatrizDinamica(cf1, cc2, sizeof(int));
    if (!matR)
    {
        return NULL;
    }

    for (i = 0; i < cf1; i++) {
        for (j = 0; j < cc2; j++) {
            suma = 0;
            for (k = 0; k < cc1; k++) {
                suma += mat1[i * cc1 + k] * mat2[k * cc2 + j];
            }
            matR[i][j] = suma;
        }
    }

    return matR;
}



void recorrerMatriz(void* matriz, int filas, int columnas, size_t tam, void (*accion)(const void* elem, const int columnas, const int col)) {
   int i,j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            accion((char*)matriz + (i * columnas + j) * tam, columnas,j);
        }
    }
}





void** crearMatrizDinamica(unsigned cf, unsigned cc, size_t tam)
{
    int i, j;
    void** mat = malloc(cf * sizeof(void*));

    if (!mat)
    {
        return NULL;
    }

    for (i = 0; i < cf; i++)
    {
        mat[i] = malloc(cc * tam);
        if (!mat[i])
        {
            for (j = 0; j < i; j++)
            {
                free(mat[j]);
            }
            free(mat);
            return NULL;
        }
    }

    return mat;
}

void destruirMatriz(void** matriz, unsigned filas)
{
    unsigned i;

    if (!matriz)
    {
        return;
    }

    for (i = 0; i < filas; i++)
    {
        free(matriz[i]);
    }

    free(matriz);
}

