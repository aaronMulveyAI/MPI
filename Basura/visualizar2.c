#include <mpi.h>
#include <stdio.h>

/*
mpicc visualizar2.c -o visualizar2
mpirun -np 1 ./visualizar2
*/

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        fprintf(stderr, "Se requieren al menos dos procesos.\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int number;
    if (rank == 0) {
         printf("Proceso 0 envia numero -1 a proceso 1");
        number = -1;
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Proceso 1 recibió número %d del proceso 0\n", number);
    }

    MPI_Finalize();
    return 0;
}
