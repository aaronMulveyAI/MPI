#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*

./compile_and_run.sh E9_Scatter

*/


int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv); 

    int procRank, procCount;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);

    const int k = 20;
    const int l = k/4;
    int vector1[k], buffer[l];

    // init for master
    if (0 == procRank){
        for (int i=0; i<k; ++i)
        {
            vector1[i]=i*35;
        }
    }
    
    MPI_Scatter(vector1, 5, MPI_INT, buffer, 5, MPI_INT, 0, MPI_COMM_WORLD);
    
    for (int i=0; i<l; ++i){
        printf("Process %i has %i -th element%i\n",procRank,i, buffer[i]);
    }
        
   
    MPI_Finalize(); 
    return EXIT_SUCCESS;
}

