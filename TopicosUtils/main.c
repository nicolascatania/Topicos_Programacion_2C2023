#include "archivos.h"
#include "funcionesGenericas.h"
#include "myString.h"
#include "vectores.h"
#include "Macros.h"
#include "matrices.h"

int main() {
    int vec[] = {15, 23, 3, 0, 16, -7, -1};
    int ce = 7;
    int elemento = 0; // Element to insert
    int* pos;

    ordenarSeleccion(vec,ce,sizeof(int),compararEntero);
    recorrerVector(vec,ce,sizeof(int),mostrarEntero);
    return 0;
}
