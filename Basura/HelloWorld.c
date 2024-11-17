#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*

clang -I/opt/homebrew/Cellar/mpich/4.1.2/include -L/opt/homebrew/Cellar/mpich/4.1.2/lib -lmpi -lpmpi HelloWorld.c -o HelloWorld.out
mpiexec -np 3 ./HelloWorld.out

*/


int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv); // Corrige a MPI_Init

    int procRank, procCount;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);


    printf("Hello world from process %d of %d\n", procRank, procCount);
        
    MPI_Finalize(); // No olvides llamar a MPI_Finalize al final


    return EXIT_SUCCESS;
}

