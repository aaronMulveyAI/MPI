
#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*

./compile_and_run.sh E912_AllReduce

*/


int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv); 

    int i = 2;
    printf("MPI_Allreduce %d \n", i);

    int procRank, procCount;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);

    int result = procRank * procCount;
    int sum = 0;

    MPI_Allreduce(&result, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    printf("proc %d: sum %d \n",procRank,sum);
    
    MPI_Finalize(); 
    return EXIT_SUCCESS;
}




















