#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "mpi.h"

/*

./compile_and_run.sh E8_Barrier

*/


int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv); 

    int procRank, procCount;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);

    double tm0, tm1;
    tm0 = MPI_Wtime();
    sleep(procRank); // Ahora sleep está declarada correctamente
    MPI_Barrier(MPI_COMM_WORLD); // all wait
    tm1 = MPI_Wtime();
    printf("proc %d, Wtime %lf \n",procRank,(tm1-tm0));
   
    MPI_Finalize(); 
    return EXIT_SUCCESS;
}


