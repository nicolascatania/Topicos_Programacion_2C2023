#include "recursivas.h"

unsigned long long factorial(int x)
{
    return x==0?1:x*factorial(x-1);
}
int rstrlen(const char* cad)
{
    return !(*cad)?0:(rstrlen(cad+1)+1);
}
void rstrcpy(char* destino,const char* origen)
{

    if(!*origen)
    {
        *destino='\0';
    }
    else
    {
        *destino=*origen;
        return rstrcpy(destino+1,origen+1);
    }
}
char* rstrchr(const char* cad, char c)
{
    if (!*cad)
    {
        return NULL;
    }

    if (*cad == c)
    {
        return (char*)cad;
    }

    return rstrchr(cad + 1, c);
}

char* rstrrchr(const char* cadena, char* c)
{
    if (*cadena == '\0')
    {
        return NULL;
    }

    // Llamada recursiva para buscar 'c' en el resto de la cadena
    char* resto = rstrrchr(cadena + 1, c);

    // Si encontramos 'c' más adelante en la cadena, retornamos ese resultado
    if (resto != NULL)
    {
        return resto;
    }

    // Si el carácter actual es igual a 'c', retornamos un puntero a él
    if (*cadena == c)
    {
        return (char*)cadena;
    }

    // Si no encontramos 'c' en esta parte de la cadena, retornamos NULL
    return NULL;

}

int resPalindromo(const char* cad)
{
    char* p1=cad;
    char* p2= cad+rstrlen(cad)-1; //p2 apunta al ultimo caracter no nulo de la cadena

    if((_resPalindromo(p1,p2)==0) || p1>p2)
    {
        return 0;
    }
    else if(p1<p2)
    {
        return _resPalindromo(p1+1,p2-1);
    }

    return 1;

}

int _resPalindromo(char* p1, char* p2)
{
    if (p1 >= p2)
    {
        return 1; // La cadena es un palíndromo
    }

    if (!ES_LETRA(*p1))
    {
        return _resPalindromo(p1 + 1, p2); // Saltar caracteres que no son letras
    }
    else if (!ES_LETRA(*p2))
    {
        return _resPalindromo(p1, p2 - 1); // Saltar caracteres que no son letras
    }
    else if (A_MAYUS(*p1) == A_MAYUS(*p2))
    {
        return _resPalindromo(p1 + 1, p2 - 1);
    }
    else
    {
        return 0; // No es un palíndromo
    }
}

char* rreverse(char* cad)
{

    char* pf= cad + rstrlen(cad)-1;
    return _rreverse(cad,pf);

}
char* _rreverse(char* p1, char*p2)
{
    //si pongo char* aux= p1; y hago lo correspondiente en el cambio de valores
    //ocurre que ,  cambia *p1, y asi lo hara tambien *aux
    //ejemplo
    /*
        EN F100= h que es p1, entonces en F100=h tambien tengo aux, ahora aux esta en F102 y p1 esta en F503 ponele
        si cambio algo dentro de F100, ese cambio repercute tanto en *p1 como en *aux, pq la dir d memoria, paso a tener otro valor
        ese cambio se refleja en todo aquello q apunte a esa dir d memoria
    */
    char aux=*p1;
    if(p2>p1)
    {
        *p1=*p2;
        *p2=aux;
        return _rreverse(p1+1,p2-1);
    }
    return p1;
}


