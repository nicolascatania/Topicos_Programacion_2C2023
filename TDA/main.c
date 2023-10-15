#include "TDAVECTOR.h"

int main()
{

    int res, elem1=10, elem2=2,elem3=13;
    char cad[]= {"Hola"};
    TDAVector vector;
    int* e;

    crearTDAVector(&vector);

    insertarEnTDA(&vector,(void*)&elem1,sizeof(int));
    insertarEnTDA(&vector,(void*)&elem2,sizeof(int));
    insertarEnTDA(&vector,cad,sizeof(cad));


    //es solo para probar que los elementos se hayan insertado bien, entiendo que acceder a los elementos de esta manera es una mala práctica.
    e= (int*)vector.vec[0].elem;
    printf("%d ",*e);
    e= (int*)vector.vec[1].elem;
    printf("%d ",*e);
    printf("%s",vector.vec[2].elem);

    int elem;
    quitarElementoEnTDA(&vector,0,(void*)&elem);


    printf("\n%d\n",elem);
    e= (int*)vector.vec[0].elem;
    printf("%d ",*e);
    printf("%s",vector.vec[1].elem);

    destruirTDAVector(&vector);

    return 0;
}
