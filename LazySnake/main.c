#include "snake.h"
#include "lotePrueba.h"

int main(int argc, char* argv[])
{

    crearMatrizAleatoria(argv[2]);
    if(LazySnakeGame(argv[2])==0)
    {
        puts("Error en la ejecucion");
    }
    return 0;
}
