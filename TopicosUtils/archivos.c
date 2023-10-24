#include "archivos.h"

int abrirArchivo(FILE** pf,char* nomArch, char* modo)
{

    *pf=fopen(nomArch,modo);

    if(!*pf)
    {
        return 0;
    }

    return 1;

}


void mostrarArchivo(char* nomArch,char*modo,size_t tam,void accion(const void*))
{
    void* buffer= malloc(tam);
    FILE* pf=fopen(nomArch,modo);
    if(!pf)
    {
        printf("No se pudo abrir %s\n",nomArch);
        return;
    }
    if(!buffer)
    {
        puts("Error pidiendo memoria");
        return;
    }

    fread(buffer,tam,1,pf);
    while(!feof(pf))
    {
        accion(buffer);
        fread(buffer,tam,1,pf);
    }
    free(buffer);
    fclose(pf);


}
