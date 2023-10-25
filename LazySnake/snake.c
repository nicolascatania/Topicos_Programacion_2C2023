#include "snake.h"
#include "lotePrueba.h"
int LazySnakeGame(char* nomArch)
{
    int tablero[MAXFIL][MAXCOL];
    int x;
//    int x= crearMatrizAleatoria(nomArch);
    int fil,col;
//    if(x==0)
//    {
//        puts("Problema creando el tablero");
//        return 0;
//    }


    x=leerMatriz(nomArch,tablero,&fil,&col);
    if(x==0)
    {
        puts("No se pudo leer el tablero");
        return 0;
    }


    puts("Tablero:");
    mostrarMatrizTablero(tablero,fil,col);

    puts("Recorrido mas barato: (no global)");
    recorrerTablero(tablero,fil,col);
    mostrarMatrizTablero(tablero,fil,col);


    return 1;

}

void recorrerTablero(int mat[MAXFIL][MAXCOL], int fil,int col)
{

    tSnake head;
    head.valor=mat[0][0];
    head.y=0;
    head.x=0;
    int ultimoMovimiento, actualMovimiento; //1 arriba, 0 abajo
    int f, adyacenteDerecho, adyacenteArriba,adyacenteAbajo, nuevox,nuevoy;

    //posiciono sobre la primer columna
    for(f=1; f<fil; f++)
    {
        if(head.valor>mat[f][0])
        {
            head.valor=mat[f][0];
            head.y=f;
        }
    }
    mat[head.y][head.x]='x';
    printf("Posicion: %d,%d\n",head.y,head.x);
    //busco menor valor adyacente
    while(head.x<col-1)
    {
        adyacenteAbajo=0;
        adyacenteArriba=0;
        adyacenteDerecho=0;
        nuevox=head.x;
        nuevoy=head.y;

        if(head.x<col-1)
        {
            adyacenteDerecho=mat[head.y][head.x+1];
            head.valor=adyacenteDerecho;
            //mantiene el y, se desplaza solo hacia la derecha
            nuevox=head.x+1;
            actualMovimiento=2;

        }
        if((head.y)-1>=0 && ultimoMovimiento!=1)
        {
            adyacenteArriba=mat[head.y-1][head.x];
            if(head.valor>adyacenteArriba)
            {
                head.valor=adyacenteArriba;
                //mantiene el x, solo se desplaza hacia arriba
                nuevox=head.x;
                nuevoy=head.y-1;
                actualMovimiento=0;
            }
        }
        if((head.y)+1<=fil-1 && ultimoMovimiento!=0)
        {
            adyacenteAbajo=mat[head.y+1][head.x];
            if(head.valor>adyacenteAbajo)
            {
                head.valor=adyacenteAbajo;
                //mantiene el x, solo se desplaza hacia abajo
                nuevox=head.x;
                nuevoy=head.y+1;
                actualMovimiento=1;
            }
        }



        //arreglar el tema del cambio de numero por 'x'
        head.x=nuevox;
        head.y=nuevoy;
        mat[head.y][head.x]='x';
        ultimoMovimiento=actualMovimiento;
        printf("Posicion: %d,%d\n",head.y,head.x);
    }


}

void mostrarMatrizTablero(int mat[MAXFIL][MAXCOL], int fil, int col)
{
    int i,j;
    for(i=0; i<fil; i++)
    {
        for(j=0; j<col; j++)
        {
            if(mat[i][j]=='x'){
                printf("%3c ", mat[i][j]);
            }
            else{
                printf("%3d ",mat[i][j]);
            }


        }
        printf("\n");
    }
}


int leerMatriz(char* nomArch, int mat[MAXFIL][MAXCOL], int* fil, int* col)
{
    FILE* pf= fopen(nomArch,"rt");

    int i,j;

    if(!pf)
    {
        return 0;
    }

    fscanf(pf,"%d %d", fil,col);
    for(i=0; i<*fil; i++)
    {
        for(j=0; j<*col; j++)
        {
            fscanf(pf,"%d ",&mat[i][j]);
        }
        fscanf(pf,"\n");
    }


    fclose(pf);
    return 1;
}
