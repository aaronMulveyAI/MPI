#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*
mpicc scater.c -o scater
mpiexec -np 4 scater
*/


int main(int argc, char* argv[]){

    MPI_Init(&argc, &argv);

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    const int k = 22;
    const int l = k / size;
    int vector[k] , buffer[l];


    if(rank == 0){

        for (int i = 0; i < k; i++){
            vector[i] = i * 2;
        }

        /*
        MPI_Scatter -> Esta función distribuye un vector de datos.
        vector -> Este es el búfer de entrada
        5 -> Este es el número de elementos en el búfer de entrada
        MPI_INT -> Este es el tipo de datos del búfer de entrada
        buffer -> Este es el búfer de salida
        5 -> Este es el número de elementos en el búfer de salida
        MPI_INT -> Este es el tipo de datos del búfer de salida
        0 -> Este es el rango del proceso raíz
        MPI_COMM_WORLD -> Este es el comunicador
        */

        MPI_Scatter(vector, 5, MPI_INT, buffer, 5, MPI_INT, 0, MPI_COMM_WORLD);

        /*
        bufer -> Region de memoria donde se almacenan los datos recibidos
        */

    }else{
        MPI_Scatter(0, 5, MPI_INT, buffer, 5, MPI_INT, 0, MPI_COMM_WORLD);
    }

    for (int i = 0; i < l; i++)
    {
        printf("Process %i has %i -th element %i\n", rank, i, buffer[i]);
    }
    

    MPI_Finalize();

    return EXIT_SUCCESS;
}