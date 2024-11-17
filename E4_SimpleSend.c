#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*

./compile_and_run.sh E4_SimpleSend

*/


int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv); 

    int procRank, procCount;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);
    
    int message = -1;
    printf("Message set to %i process %i\n", message, procRank);
    
    if(procRank == 0){
        message = 10;
        printf("Message updated to %d\n", message);
        MPI_Send(&message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD); // Pasamos la dirección de message
        printf("Message sent to process 1\n");
    }else if (procRank == 1){
        MPI_Recv(&message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); // Pasamos la dirección de message
        printf("Message received from process 0: %d\n", message);
    }
   
    MPI_Finalize(); 
    return EXIT_SUCCESS;
}

