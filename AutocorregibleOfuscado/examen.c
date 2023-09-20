#include <stdlib.h>
#include <string.h>
#include "examen.h"
void desofuscar_palabra(char* c, int longitud, const char* g)
{
    int i, pos_numerica;
    int longitud_grupo = strlen(g);
    char* pos;
    for (i = 1; i <= longitud; i++)
    {
        // Busco el caracter en permitidos
        if ((pos = strchr(g, *c)))
        {
            // Calculo la posición de la letra como índice numérico del 0 a longitud_grupo-1
            pos_numerica = pos - g;
            // Calculo la nueva posición usando el desplazamiento circular, sumando la pos (indice) y el desplazamiento, y su resto con la longitud del grupo permitido
            int nueva_pos = (pos_numerica + i) % longitud_grupo;
            // Reemplazo el caracter en c por el correspondiente en g
            *c = *(g + nueva_pos);
        }
        c++;
    }
    //el movimiento del puntero c no altera la posicion que quedó en ini_palabra dentro de la funcion desofuscar
    //esto se corrige con ini_palabra= ini_palabra+car
    //pero entiendo que sería mas óptimo que el movimiento de puntero de esta funcion
    //se refleje en desofuscar tambien, para evitar movimientos extra
}


char* desofuscar(char* linea)
{
    const char permitidos[]= {"abcdghijkoqtuv"};
    int car;
    char* ini_palabra= linea;
    while(*ini_palabra)
    {
        //aca tendriamos la primer letra de una palabra en ini_palabra
        car=esproximaPalabra(ini_palabra,&ini_palabra);
        desofuscar_palabra(ini_palabra,car,permitidos);
        ini_palabra= ini_palabra+car;
    }

    return linea;
}

int esproximaPalabra(const char* cad, char** ini)
{
    int cont = 0;
    const char* lectura = *ini; // Usamos una variable constante para no modificar cad

    // Avanzar lectura hasta encontrar una letra o el final de la cadena
    while (*lectura && !ES_LETRA(*lectura))
    {
        lectura++;
    }

    // Si llegamos al final de la cadena, no hay más palabras
    /*if (!*lectura) {
        *ini = NULL;
        return 0;
    }*/

    // Ahora lectura apunta al inicio de la próxima palabra
    *ini = (char*)lectura;

    // Contar la longitud de la palabra
    while (ES_LETRA(*lectura))
    {
        cont++;
        lectura++;
    }

    return cont;
}


