#ifndef OFUSCADO_INCLUDED
#define OFUSCADO_INCLUDED
#define ES_LETRA(c) ((c>='A'&& c<='Z')||(c>='a'&& c<='z'))

size_t quieroUnaLineaDeTextoOfuscadaV1(char* linea);
char* desofuscar(char* linea);
void desofuscar_palabra(char* c, int longitud, const char* g);
int esproximaPalabra(const char* cad, char** ini);
#endif // OFUSCADO_INCLUDED
