#include "alumnos.h"

void aluABIN(const char* nomArch, const char* modo, const char* ArchivoDestino)
{
    tAlumno alu;
    int indices[CANTCAMPOS];
    int* auxIndices = indices;
    char mat[CANTCAMPOS][MAXCOL];

    FILE* pftxt = fopen(nomArch, modo);
    FILE* pfbin = fopen(ArchivoDestino, "wb");

    if (!pftxt)
    {
        printf("No se pudo abrir %s.\n", ArchivoDestino);
        return;
    }

    if (!pfbin)
    {
        printf("No se pudo abrir %s.\n", nomArch);
        fclose(pftxt);
        return;
    }

    leerCampos(mat, pftxt);

    obtenerIndices(mat, auxIndices, DNI);
    auxIndices++;
    obtenerIndices(mat, auxIndices, LEGAJO);
    auxIndices++;
    obtenerIndices(mat, auxIndices, PROMEDIO);
    auxIndices++;
    obtenerIndices(mat, auxIndices, EDAD);
    auxIndices++;
    obtenerIndices(mat, auxIndices, GENERO);

    while (leerCampos(mat, pftxt) == 1)
    {
        prepararAlu(mat, indices, &alu);
        fwrite(&alu, sizeof(tAlumno), 1, pfbin);
    }

    fclose(pftxt);
    fclose(pfbin);
}


void obtenerIndices(char mat[CANTCAMPOS][MAXCOL], int* indices, char* campo)
{
    int i=0;
    int* aux= indices;
    while(strcmp(mat[i],campo)!=0)
    {
        i++;
    }
    *aux=i; //indices respeta las posiciones de los campos segun la def del struct, en cada posicion guarda el indice de la matriz que representa el campo de esa posicion
    aux++; //paso a la proxima posicion;

}

void prepararAlu(char mat[CANTCAMPOS][MAXCOL],int* indices, tAlumno* alu)
{
    int* aux=indices;
    sscanf(mat[*aux],"%d",&alu->dni);
    aux++;
    sscanf(mat[*aux],"%d",&alu->legajo);
    aux++;
    sscanf(mat[*aux],"%f",&alu->promedio);
    aux++;
    sscanf(mat[*aux],"%d",&alu->edad);
    aux++;
    sscanf(mat[*aux],"%c",&alu->genero);
}

int leerCampos(char mat[CANTCAMPOS][MAXCOL], FILE* pf)
{
    int i, j;
    char linea[MAXCOL];

    if (!pf) {
        return 0;
    }

    // Leo la primera línea del archivo de texto que contiene la distribución de los campos
    // Deja el cabezal listo para leer el primer registro con información
    if (fgets(linea, sizeof(linea), pf) == NULL) {
        return 0;
    }

    char* pc = linea;
    char* pfin;

    for (i = 0; i < CANTCAMPOS; i++) {
        j = 0;
        pfin = strchr(pc, '|');
        if (pfin) {
            while (pc < pfin && j < MAXCOL) {
                mat[i][j] = *pc;
                pc++;
                j++;
            }
            mat[i][j] = '\0';
            pc = pfin + 1;
        } else {
            // Si no se encuentra '|', asumimos que es la última línea y copiamos hasta el final
            while (*pc && j < MAXCOL) {
                mat[i][j] = *pc;
                pc++;
                j++;
            }
            mat[i][j-1]= '\0';
            break;
        }
    }

    return 1;
}

void leerBin()
{
    FILE* pf = fopen("alumnos.bin", "rb");
    if (!pf)
    {
        return;
    }

    tAlumno alu;

    fread(&alu, sizeof(tAlumno), 1, pf);
    while (!feof(pf))
    {
        printf("%d %d %.2f %d %c\n", alu.dni, alu.legajo, alu.promedio, alu.edad, alu.genero);

        fread(&alu, sizeof(tAlumno), 1, pf);
    }
    fclose(pf);
}

