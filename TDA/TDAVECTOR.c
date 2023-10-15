#include "TDAVECTOR.h"

int crearTDAVector(TDAVector* tdav)
{
    tdav->vec=malloc(MINALLOC*sizeof(tNodo));
    if(!tdav->vec)
    {
        return 0;
    }
    tdav->ce=0;
    tdav->tam=MINALLOC;

    return 1;

}

int insertarEnTDA(TDAVector* tdav, void* elem, size_t tamElem)
{
    if (tdav->ce >= tdav->tam) {
        if (!agregarMemoriaTDA(tdav)) {
            return 0;
        }
    }

    tNodo* nodo = (tNodo*)malloc(sizeof(tNodo));
    if (nodo == NULL) {
        return 0;
    }

    nodo->elem = malloc(tamElem);
    if (nodo->elem == NULL) {
        free(nodo);
        return 0;
    }

    nodo->tamElem = tamElem;
    memcpy(nodo->elem, elem, tamElem);


    memcpy(&tdav->vec[tdav->ce], nodo, sizeof(tNodo));
    tdav->ce++;


    free(nodo);

    return 1;
}


int agregarMemoriaTDA(TDAVector* tdav) {
    int i;
    TDAVector temp;
    temp.tam = tdav->tam + ESPACIOEXTRA;
    temp.ce = tdav->ce;
    temp.vec = (tNodo*)malloc(temp.tam * sizeof(tNodo));

    if (!temp.vec) {
        return 0;
    }

    for (i = 0; i < tdav->ce; i++) {
        temp.vec[i].tamElem = tdav->vec[i].tamElem;
        temp.vec[i].elem = malloc(tdav->vec[i].tamElem);
        memcpy(temp.vec[i].elem, tdav->vec[i].elem, tdav->vec[i].tamElem);
    }

    destruirTDAVector(tdav);

    tdav->vec = temp.vec;
    tdav->tam = temp.tam;
    tdav->ce = temp.ce;

    return 1;
}


int quitarElementoEnTDA(TDAVector* tdav, size_t pos, void* buffer)
{
    TDAVector temp = *tdav;

    if (pos >= temp.ce) {
        return -1;
    }

    memcpy(buffer, temp.vec[pos].elem, temp.vec[pos].tamElem);


    for (size_t i = pos; i < temp.ce - 1; i++) {
        temp.vec[i] = temp.vec[i + 1];
    }

    temp.ce--;

    *tdav = temp;

    return 0;
}

void destruirTDAVector(TDAVector* tdav) {
    tNodo* temp = tdav->vec;
    int i;
    for(i=0; i<tdav->ce;i++)
    {
        free(temp->elem);
        temp++;

    }
    free(tdav->vec);
    tdav->vec=NULL;
    tdav->tam = 0;
    tdav->ce=0;
}



void mostrarTDAVector(TDAVector* tdav, void accion(const void*))
{
    TDAVector aux;
    aux.vec=tdav->vec;
    int i;
    for(i=0; i<tdav->ce; i++)
    {
        accion(aux.vec->elem);
        aux.vec++;
    }
}

void mostrarEntero(const void* elem)
{
    int num= *((int*)elem);
    printf("%d ", num);
}
