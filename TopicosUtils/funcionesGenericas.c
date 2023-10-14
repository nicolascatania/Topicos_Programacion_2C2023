#include "funcionesGenericas.h"




//funciones de tipo

void mostrarEntero(void*a)
{
    printf("%d ",*(int*)a);
}
void mostrarFloat(void*a)
{
    printf("%.2f  ",*(float*)a);
}

int compararEntero(const void*a, const void*b)
{
    int cmp;
    cmp=*(int*)a-*(int*)b;

    return cmp;
}

int compararFloat(const void*a, const void*b)
{
    int cmp;
    cmp=*(float*)a-*(float*)b;

    return cmp;
}

void acumularEnteros(const void* dato, void* res)
{
    *(int*)res+= *(int*)dato;
}

void acumularFloats(const void*dato, void* res)
{
    *(float*)res+=*(float*)dato;
}

void acumularDouble(const void*dato, void* res)
{
    *(double*)res+=*(double*)dato;
}

void promedioEnterosReduce(const void* dato, void* res)
{
    int termino = *(int*)dato;
    *(float*)res+=(float)termino/4;
}
void promedioFloatsReduce(const void* dato, void* res)
{
    float termino = *(float*)dato;
    *(float*)res+=(float)termino/4;
}
void promedioDoubleReduce(const void* dato, void* res)
{
    double termino = *(double*)dato;
    *(float*)res+=(float)termino/4;
}

int filtrarEnterosMenoresA(const void* dato, void* parametro)
{

    if(compararEntero(dato,parametro)<0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
int filtrarEnterosMayoresA(const void* dato, void* parametro)
{

    if(compararEntero(dato,parametro)>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int filtrarEnterosIgualesA(const void* dato, void* parametro)
{

    if(compararEntero(dato,parametro)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int filtrarFloatsMenoresA(const void* dato, void* parametro)
{

    if(compararFloat(dato,parametro)<0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
int filtrarFloatsMayoresA(const void* dato, void* parametro)
{

    if(compararFloat(dato,parametro)>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int filtrarFloatsIgualesA(const void* dato, void* parametro)
{

    if(compararFloat(dato,parametro)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}



//funciones genericas

void* busquedaBinaria(void* vec, void* clave, size_t tam, int ce, int cmp(const void* a, const void* b))
{
    int comparacion;
    void* pos;
    int tamanyo_actual = ce;

    if (ce == 0)
    {
        return NULL;
    }

    while (tamanyo_actual > 0)
    {
        pos = vec + (tam * (tamanyo_actual / 2));
        comparacion = cmp(clave, pos);

        if (comparacion == 0)
        {
            return pos;
        }
        else if (comparacion < 0)
        {
            tamanyo_actual = tamanyo_actual / 2;
        }
        else
        {
            vec = pos + tam;
           tamanyo_actual = (tamanyo_actual - 1) / 2;
        }
    }

    return NULL;
}


void intercambio(void*a, void*b,size_t tam)
{
    int i;
    char aux;
    for(i=0; i<tam; i++)
    {
        aux=*(char*)a;
        *(char*)a=*(char*)b;
        *(char*)b=aux;

        a++;
        b++;
    }
}



void reduce(const void* vec, int ce, size_t tam, void* resultado, void accion(const void* dato, void* res))
{
    int i;
    for(i=0; i<ce; i++)
    {
        accion(vec,resultado);
        vec+=tam;
    }
}

void filter(void* vec, int* ce, size_t tam, void* filtro(const void* dato,const void* parametro),void* parametro)
{
    int i;
    void* lectura=vec;
    int ce_vecFiltrado=0;
    for(i=0; i<*ce; i++)
    {
        if(filtro(lectura,parametro))
        {
            intercambio(vec,lectura,tam);
            vec+=tam;
            ce_vecFiltrado++;
        }

        lectura+=tam;
    }
    *ce=ce_vecFiltrado;

}


//recursivas

int rmap(void* vec, int ce, size_t tam, void accion(void*))
{
    if(ce<1)
    {
        return 0;
    }
    accion(vec);
    return rmap(vec+tam, ce-1,tam,accion)+1;
}
