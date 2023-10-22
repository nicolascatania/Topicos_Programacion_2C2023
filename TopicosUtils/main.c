#include "archivos.h"
#include "funcionesGenericas.h"
#include "myString.h"
#include "vectores.h"
#include "Macros.h"
#include "matrices.h"


int main() {

    int mat[3][3]={{1,2,3},{1,2,3},{1,2,3}};
    int mat2[3][MAXCOL]={{1,2,3},{1,2,3},{1,2,3}};
    int cf=3;
    int** matR;

    matR= multiplicarMatricesEnteras(&mat[0][0],&mat2[0][0],cf,cf,cf,cf);




    recorrerMatriz(matR, 3, 3,sizeof(int), mostrarEnteroMatriz);

    //recorrerMatriz(matR,cf,cf,sizeof(int),mostrarEntero);

    destruirMatriz((void**)matR,cf);

    return 0;
}
