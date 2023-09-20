#include "funcionesGenericas.h"
int main()
{
    /*int*menor;
    float* menorf;
    int vec[10]={20,2,3,4,1,6,7,8,9,-10};
    float vecf[5]={1.2,-34,5.5,123.3,4};
    recorrerVector(vec,10,sizeof(int),mostrarEntero);
    puts("");
    recorrerVector(vecf,5,sizeof(float),mostrarFloat);
    puts("");
    menor= buscarMenor(vec,10,sizeof(int),compararEntero);
    printf("%d", *menor);
    puts("");
    menorf= buscarMenor(vecf,5,sizeof(float),compararFloat);
    printf("%.2f", *menorf);*/

    int vec[]={1,16,3,4,10,150,1};
    int ce=sizeof(vec)/sizeof(int);
    int parametro=5;
    filter(vec,&ce,sizeof(int),filtrarEnterosMenoresA,&parametro);
    recorrerVector(vec,ce,sizeof(int),mostrarEntero);



    return 0;
}
