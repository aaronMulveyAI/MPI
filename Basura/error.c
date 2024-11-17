// Inclusión de las bibliotecas estándar de C y la biblioteca de MPI
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

/*
* mpicc -std=c99 error.c -o error
* mpiexec -np 3 error
*/

/*
mpicc: Es el compilador para programas MPI en C. 
-std=c99: Estándar C99 del lenguaje C.
*/
int main(int argc, char* argv[]) {
    // Declaración de variables
    int procRank, procCount, error;

    // Inicializa el entorno MPI. Debe ser llamado antes de cualquier otra función de MPI.
    MPI_Init(&argc, &argv);

    // Obtiene el número total de procesos en la ejecución actual de MPI
    MPI_Comm_size(MPI_COMM_WORLD, &procCount); // MPI_COMM_WORLD includes all of the started processes
    

    // Obtiene el rango (identificador único) del proceso actual dentro de MPI_COMM_WORLD
    error = MPI_Comm_rank(MPI_COMM_WORLD, &procRank);

    // Imprime el rango del proceso, el número total de procesos y cualquier error
    printf("Start[%d]/[%d], error %d \n", procRank, procCount, error);

    // Finaliza el entorno MPI. Después de esta llamada, no se deben usar más funciones de MPI.
    MPI_Finalize();

    return EXIT_SUCCESS;
}

