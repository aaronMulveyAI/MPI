#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*

./compile_and_run.sh E5_MoreSend

*/


int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv); 

    int procRank, procCount;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);

    const int length = 5; // Cambia la salida si length!=5
    int message[length];
    enum { tagSend = 1 };

    if(procRank == 0){
        for (int i = 1; i < procCount; i++) {
            MPI_Recv(message, length, MPI_INT, i, tagSend, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        printf("Message received from process %d: \n", message[0]);
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
