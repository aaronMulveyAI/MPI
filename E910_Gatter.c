#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*

./compile_and_run.sh E910_Gatter

*/


int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv); 

    int procRank, procCount;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);

    const int k = 20;
    const int l = k/4;
    int vector2[l], buffer[k];
    
    
    for (int i=0; i<l; ++i){
        vector2[i] = i - 10;
    }
        
    MPI_Gather(vector2,5,MPI_INT,buffer,5,MPI_INT,0,MPI_COMM_WORLD);
    
    if (0 == procRank) {
        for (int i=0; i<k; ++i){
            printf("vectors %i-th element: %i\n", i, buffer[i]);
        }
    }
   
    MPI_Finalize(); 
    return EXIT_SUCCESS;
}

