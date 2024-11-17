#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*

./compile_and_run.sh E

*/


int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv); 

    int procRank, procCount;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);
   
    MPI_Finalize(); 
    return EXIT_SUCCESS;
}

