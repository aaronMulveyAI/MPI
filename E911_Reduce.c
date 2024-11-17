#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*

./compile_and_run.sh E911_Reduce

*/


int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv); 

    int procRank, procCount;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);
   
    int result = procRank * procCount;
    int sum = 0;

    MPI_Reduce(&result, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    
    if (0 == procRank) {
        printf("sum %d \n",sum);
    }
    MPI_Finalize(); 
    return EXIT_SUCCESS;
}

