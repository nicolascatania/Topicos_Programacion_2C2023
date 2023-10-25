#include "lotePrueba.h"

int crearMatriz(char* nomArch)
{
    int mat[MAXFIL][MAXCOL]={{5,3,2,5,6,3},{1,1,3,1,1,1},{8,2,1,7,2,5}};
    FILE* pf= fopen(nomArch, "wt");

    if(!pf)
    {
        return 0;
    }

    int fil= 3;
    int col= 6;

    fprintf(pf,"%d %d\n",fil,col);
    for(int i=0;i<fil;i++)
    {
        for(int j=0;j<col;j++)
        {
            fprintf(pf,"%d ", mat[i][j]);
        }
        fprintf(pf,"\n");
    }

    fclose(pf);

    return 1;


}

int crearMatrizAleatoria(char* nomArch){
    FILE* pf=fopen(nomArch,"wt");
    if(!pf){
        return 0;
    }
    srand(time(NULL));

    int fil,col,valor;
    fil= (rand()%10)+1;
    col= (rand()%10)+1;
    fprintf(pf,"%d %d\n",fil,col);
    for(int i=0;i<fil;i++)
    {
        for(int j=0;j<col;j++)
        {
            valor= rand()%1000;
            fprintf(pf,"%d ",valor);

        }
        fprintf(pf,"\n");

    }


    fclose(pf);
    return 1;



}
