#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

/*
mpicc -std=c99 arraydistI-parallel.c -o arraydistI-parallel
./arraydistI-parallel
*/

int countPattern(const int v[], const int size, const int pattern);
void initArray(int v[], const int size, const int mod);
void printArray(const int v[], const int size);


int main(int argc, char* argv[]){

    MPI_Init(&argc, &argv);

    int procRank, procCount;
    MPI_Comm_size(MPI_COMM_WORLD, &procCount);
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);

    // Data memory
    const int k = 50;
    int pattern = 0;
    int count = 0;
    int totalCount = 0;

    // Suponiendo una distribución uniforme del trabajo
    int local_k = k / procCount;

    // Esta asignando espacio en la memooria para k elementos del tipo int
    int* local_vector = (int*)malloc(k * sizeof(int));

    if(procRank == 0){
        
        int* vector = (int*)malloc(k * sizeof(int));
        initArray(vector, k, 4);
        
        // Distribuye segmentos del array a cada proceso
        MPI_Scatter(vector, local_k, MPI_INT, local_vector, local_k, MPI_INT, 0, MPI_COMM_WORLD);
    
    }else{    
        
        /*
        Recive el segmento del array
        MPI_Scatter -> Esta función distribuye un vector de datos.
        NULL -> Este es el búfer de entrada
        0 -> Este es el número de elementos en el búfer de entrada
        MPI_INT -> Este es el tipo de datos del búfer de entrada
        local_vector -> Este es el búfer de salida
        local_k -> Este es el número de elementos en el búfer de salida
        MPI_INT -> Este es el tipo de datos del búfer de salida
        0 -> Este es el rango del proceso raíz
        MPI_COMM_WORLD -> Este es el comunicador
        */
        MPI_Scatter(NULL, 0, MPI_INT, local_vector, local_k, MPI_INT, 0, MPI_COMM_WORLD);
    }

    count = countPattern(local_vector, local_k, pattern);
    
    /*
    MPI_Reduce -> Esta función reduce los valores de todos los procesos a un solo valor.
    &count -> Este es el búfer de entrada
    &totalCount -> Este es el búfer de salida
    1 -> Este es el número de elementos en el búfer
    MPI_INT -> Este es el tipo de datos del búfer
    MPI_SUM -> Esta es la operación de reducción
    0 -> Este es el rango del proceso raíz
    MPI_COMM_WORLD -> Este es el comunicador
    */

    MPI_Reduce(&count, &totalCount, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (procRank == 0) {
        printf("Number %i was found %i times in the array\n", pattern, totalCount);
    }

    // Libera la memoria, importante para evitar fugas de memoria.
    free(local_vector);
    MPI_Finalize(); // Final

    return EXIT_SUCCESS;
}

//Cuenta las ocurrencias de un patron en un vector de datos
int countPattern(const int v[], const int size, const int pattern) {
    int count = 0;

    for(int i = 0; i < size; ++i){
        if(pattern == v[i]){
            ++count;
        }
    }

    return count;
}

// Populates the array
void initArray(int v[], const int size, const int mod) {
    
    for(int i = 0; i < size; ++i){
        v[i] = rand() % mod;
    }
}

// Basic method for array printing
void printArray(const int v[], const int size) {
    
    printf("Array:\n");
    
    for(int i = 0; i < size; ++i){
        printf(" %i", v[i]);
        printf("\n");
    }
}
