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
    int i=0;
    char fraseLeida[MAXLENGHT];
    char frases[30][MAXLENGHT];
    char** matResultado;


    while(obtenerFrase(fraseLeida) && i<30)
    {
        insertarOrdenado2(frases,fraseLeida,30,&i);
    }


    matResultado=obtenerCoincidencias(frases,i);


    for(int j=0; j<i; j++)
    {
        printf("%s\n",matResultado[j]);
    }
    destruirMatriz((void**)matResultado,i);
}

char** obtenerCoincidencias(char mat[][MAXLENGHT],const int ce)
{
    int  frasesAnalizadas=0, cantLetras,frasesCoincidentes=0,longitudLeida, cantCaracteres;
    char* palabra= malloc(MAXLENGHT*sizeof(char));
    char** matResultado= (char**)crearMatrizGenerica(ce,MAXLENGHT,sizeof(char));

    *(palabra)='\0';
    while(frasesAnalizadas<ce)
    {
        cantCaracteres=0;
        cantLetras=0;
        longitudLeida= strlen(mat[frasesAnalizadas]);
        while(longitudLeida>0)
        {
            cantLetras=obtenerPalabra(mat[frasesAnalizadas][cantCaracteres],palabra, &cantCaracteres);
            if(buscarPalabra(mat[frasesAnalizadas+1],palabra)!=-1)
            {
                strcpy(matResultado[frasesCoincidentes],mat[frasesAnalizadas]);
                frasesCoincidentes++;
            }
            longitudLeida-=cantCaracteres;

        }
        frasesAnalizadas++;

    }

    free(palabra);
    return matResultado;

}

int obtenerPalabra(char* frase, char* palabra, int* caracteresLeidos)
{
    char* lectura= frase;
    int i = 0, cantLetras = 0;
    while (!ESLETRA(*lectura))
    {
        lectura++;
        (*caracteresLeidos)++;
    }

    while (ESLETRA(*lectura))
    {
        palabra[cantLetras] = *lectura; // Asignar el carácter directamente
        cantLetras++;
        lectura++;
         (*caracteresLeidos)++;
    }

    palabra[cantLetras] = '\0'; // Añadir el terminador nulo al final de la palabra

    return cantLetras;
}

int buscarPalabra(const char *cadena, const char *palabra)
{
    // Obtener la longitud de la cadena y la palabra
    int longitudCadena = strlen(cadena);
    int longitudPalabra = strlen(palabra);

    // Recorrer la cadena
    for (int i = 0; i <= longitudCadena - longitudPalabra; i++)
    {
        // Comprobar si la subcadena de la cadena coincide con la palabra
        if (strncmp(cadena + i, palabra, longitudPalabra) == 0)
        {
            return i; // Devolver la posición de la palabra encontrada
        }
    }

    return -1; // La palabra no se encontró en la cadena
}

void destruirMatriz(void **matriz, int filas)
{
    if (matriz == NULL)
    {
        return; // No hacer nada si la matriz ya es NULL
    }

    for (int i = 0; i < filas; i++)
    {
        free(matriz[i]); // Liberar la memoria de cada fila de la matriz
    }

    free(matriz); // Liberar la memoria de la matriz principal
}

void **crearMatrizGenerica(int filas, int columnas, size_t tamanoElemento)
{
    void **matriz = (void **)malloc(filas * sizeof(void *));
    if (matriz == NULL)
    {
        return NULL; // Fallo en la asignación de memoria
    }

    for (int i = 0; i < filas; i++)
    {
        matriz[i] = malloc(columnas * tamanoElemento);
        if (matriz[i] == NULL)
        {
            // Si no se puede asignar memoria para una fila, liberamos la memoria previamente asignada
            for (int j = 0; j < i; j++)
            {
                free(matriz[j]);
            }
            free(matriz);
            return NULL; // Fallo en la asignación de memoria
        }
    }

    return matriz;
}
