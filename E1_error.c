#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*
./compile_and_run.sh E1_error
*/


int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv); 

    int procRank, procCount, error;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);

    // error = 0 si no hay error // error = 1 si hay error
    error = MPI_Comm_rank(MPI_COMM_WORLD, &procRank);

    printf("Start[%d]/[%d], error %d \n",procRank,procCount,error);
        
    MPI_Finalize(); 


    return EXIT_SUCCESS;
}

