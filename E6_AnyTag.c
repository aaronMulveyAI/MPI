#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*

./compile_and_run.sh E6_AnyTag

*/


int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv); 

    int procRank, procCount;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);


    const int length = 5; // Cambia la salida si length!=5
    int message[length];
    enum { tagSend = 1 };

    if (procRank == 0) {
        for(int i = 1; i < procCount; i++) {
            
            MPI_Status status;
            
            MPI_Recv(message, length, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

            printf("Message:    %i %i %i %i %i\n",message[0],
            message[1],message[2],message[3],message[4]);
            printf("Source:     %d\n",status.MPI_SOURCE);
            printf("Tag:        %d\n",status.MPI_TAG);
        }

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

