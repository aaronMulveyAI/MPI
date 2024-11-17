#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"


/*
mpicc visualizar.c -o visualizar
mpiexec -np 3 visualizar
*/

int main(int argc, char* argv[]){

    MPI_Init(&argc, &argv); /* MPI_COMM_WORLD comunicador que engloba todos procesos*/

    int k;  /* Rango del proceso */
    int p;  /* Numero de procesos */

    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &k);

    printf("Soy el proceso %d de %d\n", k, p);

    MPI_Finalize();
    
    return EXIT_SUCCESS;
}