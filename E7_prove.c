#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*

./compile_and_run.sh E7_prove

*/


int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv); 

    int procRank, procCount;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);


    const int length = 5;
    int message[length];
    enum { tagSend = 1 };

    if (procRank == 0) {
        
        MPI_Status status;
        MPI_Probe(0, tagSend, MPI_COMM_WORLD, &status);
        int k;

        MPI_Get_count(&status, MPI_INT, &k);        
        int* message = (int*)malloc(k*sizeof(int));

        MPI_Recv(message, k, MPI_INT, MPI_ANY_SOURCE, tagSend, MPI_COMM_WORLD, &status);

        printf("Message:    %i %i %i %i %i\n",
            message[0],
            message[1],
            message[2],
            message[3],
            message[4]);
        

    } else {
        
        for (int i = 0; i < length; i++) {
            message[i] = procRank;
        }
        MPI_Send(message, length, MPI_INT, 0, tagSend, MPI_COMM_WORLD); 
        printf("Message sent from process %d: \n", procRank); 

    }
    
   
    MPI_Finalize(); 
    return EXIT_SUCCESS;
}

