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



    e= (int*)vector.vec[0].elem;
    printf("%d ",*e);
    e= (int*)vector.vec[1].elem;
    printf("%d ",*e);
    printf("%s",vector.vec[2].elem);






    /*int elem;
    quitarElementoEnTDA(&vector,1,(void*)elem);

    printf("%d",elem);*/


    destruirTDAVector(&vector);

    return 0;
}
