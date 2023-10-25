#include "snake.h"
#include "lotePrueba.h"

int main(int argc, char* argv[])
{

    crearMatrizAleatoria(argv[3]);
    if(LazySnakeGame(argv[3])==0)
    {
        puts("Error en la ejecucion");
    }







    return 0;
}
