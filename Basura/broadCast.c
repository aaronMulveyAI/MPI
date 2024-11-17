#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*
mpicc broadCast.c -o broadCast
mpiexec -np 3 broadCast
*/

int main(int argc, char* argv[]){

    MPI_Init(&argc, &argv);

    int procRank;
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);

    int message = -1;
    enum {tag = 1};
    
    if (procRank == 0){
        message = 52;
    }


    /*
    &message -> Este es un puntero al mensaje que se va a difundir
    1 -> Este es el número de elementos en el búfer
    MPI_INT -> Este es el tipo de datos del búfer
    0 -> Este es el rango del proceso raíz
    MPI_COMM_WORLD -> Este es el comunicador
    */

    MPI_Bcast(&message, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d recive. broadcast %d\n", procRank, message);

    MPI_Finalize(); 
    return EXIT_SUCCESS;
}