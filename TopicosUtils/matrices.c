#include "matrices.h"
#include "funcionesGenericas.h"

void recorrerMatriz(void** mat,unsigned cf,unsigned cc,size_t tam, void accion(const void* elem))
{
    unsigned f,c;
    for(f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
        {
            accion(&mat[f][c]);
        }
        puts("");
    }
}


void** crearMatrizDinamica(unsigned cf, unsigned cc, size_t tam) {
    int i, j;
    void** mat = malloc(cf * sizeof(void*));

    if (!mat) {
        return NULL;
    }

    for (i = 0; i < cf; i++) {
        mat[i] = malloc(cc * tam);
        if (!mat[i]) {
            for (j = 0; j < i; j++) {
                free(mat[j]);
            }
            free(mat);
            return NULL;
        }
    }

    return mat;
}

void destruirMatriz(void** matriz, unsigned filas) {
    unsigned i;

    if (!matriz) {
        return;
    }

    for (i = 0; i < filas; i++) {
        free(matriz[i]);
    }


    free(matriz);
}

