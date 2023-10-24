#include "vectores.h"
#include "funcionesGenericas.h"


void insertarEnVectorOrdenado(void* vec, int* ce, size_t tam, void* elem, Cmp cmp) {
    int i = 0, j;

    if (*ce == 0) {
        memcpy(vec, elem, tam);
    } else {
        while (i < *ce && cmp(vec + i * tam, elem) < 0) {
            i++;
        }

        for (j = *ce; j > i; j--) {
            memcpy(vec + j * tam, vec + (j - 1) * tam, tam);
        }

        memcpy(vec + i * tam, elem, tam);
    }

    (*ce)++;
}


void* crearVectorDinamico(unsigned n, size_t tam)
{
    void* vec= malloc(n*tam);
    if(!vec)
    {
        return NULL;
    }
    return vec;
}

void recorrerVector(void* vec,int ce,size_t tam,void accion(void*))
{

    int i;
    for(i=0; i<ce; i++)
    {
        accion(vec);
        vec+=tam;
    }
}


void* buscarMenor(void* vec,int ce,size_t tam,Cmp cmp)
{
    if(!vec)
        return NULL;

    void* menor= vec;
    int i;
    for(i=1; i<=ce; i++)
    {
        if(cmp(menor,vec)>0)
        {
            //lo que hay en la siguiente posicion, es menor al menor ya establecido, actualizamos el valor menor
            menor=vec;
        }
        vec+=tam;
    }

    return menor;
}

void ordenarSeleccion(void* vec, int ce, size_t tam,Cmp cmp)
{
    //buscar el menor
    //una vez q lo encontre hago intercambio entre el menor y donde yo estoy parado (primera posicion)
    //paso a la sgte posicion y salgo a buscar el menor devuelta
    //repito
    int i;
    void*menor;
    for(i=0; i<ce; i++)
    {

        menor= buscarMenor(vec,ce-i,tam,cmp);
        intercambio(menor,vec, tam);
        vec+=tam;
    }
}
