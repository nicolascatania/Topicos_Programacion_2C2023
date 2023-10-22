#include <stdio.h>
#include "examen.h"


void obtenerNInicialesConMasApariciones(int cantidadIniciales)
{
    int i,ce=0;
    tInicial* inicial;
    tInicial vecIniciales[LETRAS_ABECEDARIO];
    tInicial* inicialesResultado = malloc(sizeof(tInicial)*cantidadIniciales);
    char fraseLeida[MAXLENGHT];

    llenarVectorIniciales(vecIniciales);

    setearResultado(inicialesResultado, cantidadIniciales);


    while(obtenerFrase(fraseLeida))
    {
        contarInicial(fraseLeida,vecIniciales);
    }


    for(i=0; i<LETRAS_ABECEDARIO; i++)
    {

        inicial = vecIniciales + i;
        insertarEnVectorOrdenado(inicialesResultado,inicial,cmpIniciales,cantidadIniciales,&ce, sizeof(tInicial));


    }


    mostrarVectorIniciales(inicialesResultado, &cantidadIniciales);

    free(inicialesResultado);

}

void setearResultado(tInicial* vec, int elementos)
{
    int i;

    for(i=0; i<elementos; i++)
    {
        vec->apariciones=0;
        vec++;
    }
}

void mostrarVectorIniciales(tInicial* vec, int* ce)
{
    int i;
    for(i=0; i<*ce; i++)
    {
        printf("%c\n",vec->inicial);
        vec++;
    }
}

int cmpIniciales(const void*a, const void*b)
{
    tInicial elem1= *((tInicial*)a);
    tInicial elem2= *((tInicial*)b);

    return elem1.apariciones-elem2.apariciones;
}

void llenarVectorIniciales(tInicial* vec)
{
    int i;
    for(i=0; i<LETRAS_ABECEDARIO; i++)
    {
        vec->apariciones=0;
        vec->inicial=('A'+i);
        vec++;
    }
}

void insertarEnVectorOrdenado(void* vec, void* elem, int cmp(const void* a, const void*b),int tamVector, int* ce, size_t tam)
{
    int i=0,j;
    if(*ce==0)
    {
        memcpy(vec,elem,tam);
        (*ce)++;
    }
    else
    {
        while(i<*ce && cmp(vec+(tam*i),elem)>0)
        {
            i++;
        }

        for(j=tamVector-1; j>i; j--)
        {
            memcpy(vec+(tam*j),vec+(tam*(j-1)),tam);
        }

        if(j>=i)
        {
            memcpy(vec+(tam*j),elem,tam);
        }

        if(*ce<tamVector)
        {
            (*ce)++;
        }
    }


}

void contarInicial(char* frase, tInicial* vecIniciales)
{
    tInicial* inicial;
    inicial=(vecIniciales + (AMAYUS(*frase)%65));
    inicial->apariciones+=1;
}

void obtener5FrasesMasLargasMatriz()
{
    char matR[5][MAXLENGHT];
    char fraseLeida[MAXLENGHT];
    int ce=0,i;

    while(obtenerFrase(fraseLeida))
    {
        insertarOrdenado2(matR, fraseLeida,5,&ce);

    }

    for(i=0; i<5; i++)
    {
        printf("%s\n",matR[i]);
    }

}

void insertarOrdenado2(char mat[][MAXLENGHT], char* frase, int fil, int* ce)
{

    int i=0,j;

    if(*ce == 0)
    {
        strcpy(mat[0], frase);
        (*ce)++;
    }

    else
    {
        while(i<*ce && strlen(frase)<strlen(mat[i]))
        {
            i++;
        }
        for(j=fil-1; j>i; j--)
        {
            strcpy(mat[j],mat[j-1]);
        }
        strcpy(mat[j], frase);

        if(*ce<fil)
        {
            (*ce)++;
        }
    }


}




void mostrarFrasesConPalabrasCoincidentes()
{
    int i = 0,j;
    char fraseLeida[MAXLENGHT];
    char frases[FRASESMAX][MAXLENGHT];
    char matResultado[FRASESMAX][MAXLENGHT];

    for (j = 0; j < FRASESMAX; j++)
    {
        matResultado[j][0] = '\0';
    }

    while (obtenerFrase(fraseLeida) && i < FRASESMAX)
    {
        insertarOrdenado2(frases, fraseLeida, FRASESMAX, &i);
    }

    obtenerCoincidencias(matResultado, frases, i);

    for ( j = 0; j < i; j++)
    {
        printf("%s\n", matResultado[j]);
    }
}



void obtenerCoincidencias(char matResultado[FRASESMAX][MAXLENGHT], char frases[FRASESMAX][MAXLENGHT], int cantidadFrases)
{

    int i,j, caracteresLeidos=0;
    char palabra[MAXLENGHT];
    for(i=0; i<cantidadFrases; i++)
    {
        caracteresLeidos=obtenerPalabra(frases[i],palabra, caracteresLeidos);
        while(caracteresLeidos>0)
        {
            for(j=i+1; j<cantidadFrases; j++)
            {
                if(buscarPalabra(frases[j],palabra))
                {
                    insertarFrasesCoincidentes(matResultado,frases[i], frases[j], cantidadFrases);
                }
            }
            caracteresLeidos=obtenerPalabra(frases[i],palabra, caracteresLeidos);
        }

    }

}

int buscarPalabra(char* string, char* substring)
{
    char palabra[MAXLENGHT]="\0";
    char* pal=palabra;
    char* ps= string;
    char* psub=substring;
    int largoSub= strlen(substring);
    int largoPal;
    int coincidencias;
    while(*ps)
    {
        while(!ESLETRA(*ps))
        {
            ps++;
        }
        while(ESLETRA(*ps))
        {
            *pal= *ps;
            pal++;
            ps++;
        }
        pal=palabra;
        largoPal= strlen(palabra);
        coincidencias=0;
        while(*pal)
        {
    //podria usar strcmp
            if(*pal==*psub)
            {
                pal++;
                psub++;
                coincidencias++;
            }
            else
            {
                memset(palabra, 0, sizeof(palabra));
                pal=palabra;
                psub= substring;
            }
        }

        if(coincidencias==largoSub && strlen(palabra)==strlen(substring) )
        {
            return 1;
        }


    }
    return 0;
}

int obtenerPalabra(char* frase, char* palabra, int car)
{
    int cantCar=car;
    char* pf= frase+ cantCar;
    char* pc=palabra;

    if(!*pf)
    {
        return 0;
    }

    while(!ESLETRA(*pf))
    {
        pf++;
        cantCar++;
    }

    while(ESLETRA(*pf))
    {
        cantCar++;
        *pc = *pf;
        pf++;
        pc++;
    }
    *pc = '\0';

    if(!*pf)
    {
        return 0;
    }

    return cantCar;
}

void insertarFrasesCoincidentes(char mat[FRASESMAX][MAXLENGHT],char* frase, char* fraseCoincidente, int cantidadFrases)
{
    int i, j, repetida=0, repetidaCoincidente=0;
    if(mat[0][0]=='\0')
    {
        strcpy(mat[0],frase);
        strcpy(mat[1],fraseCoincidente);
    }
    else
    {
        for(i=0; i<cantidadFrases; i++)
        {
            if(strcmpi(mat[i],frase)==0)
            {
                repetida=1;
            }
            if(strcmpi(mat[i],fraseCoincidente)==0)
            {
                repetidaCoincidente=1;
            }
        }

        if(!repetida)
        {
            j=0;
            while(mat[j][0]!='\0')
            {
                j++;
            }
            strcpy(mat[j],frase);
        }
        if(!repetidaCoincidente)
        {
            j=0;
            while(mat[j][0]!='\0')
            {
                j++;
            }
            strcpy(mat[j],fraseCoincidente);
        }
    }
}
