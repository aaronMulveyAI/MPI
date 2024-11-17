#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*
* mpicc rank.c -o rank
* ./rank
* mpiexec -np 3 rank
*/

int main(int argc, char *argv[]){

    int procRank, procCount;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &procCount);

    // Obtiene el rango (ID) del proceso llamador dentro de MPI_COMM_WORLD.
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);

    printf("Start[%d]/[%d]\n", procRank, procCount);

    MPI_Finalize();

    return EXIT_SUCCESS;
}