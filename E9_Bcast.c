#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*

./compile_and_run.sh E9_Bcast

*/


int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv); 

    int procRank, procCount;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);

    int message = -1;
    enum { tagSend = 1 };
        
    if (0 == procRank) {
        message = 42;
    }
    
    //        data,     count, datatype,  root,  communicator
    MPI_Bcast(&message, 1,     MPI_INT,   0,     MPI_COMM_WORLD);
    printf("proc %d recv. bcast %d \n",procRank,message);
   
    MPI_Finalize(); 
    return EXIT_SUCCESS;
}

