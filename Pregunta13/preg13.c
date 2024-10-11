#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char v_cadenas[8][20] = {"cad0", "cad1", "cad2", "cad3", "cad4", "cad5", "cad6", "cad7"};
    int n = 8;
    int procesador, tamanio;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
    MPI_Comm_size(MPI_COMM_WORLD, &tamanio);

    if (procesador == 0) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                MPI_Send(v_cadenas[i], 20, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
            } else {
                MPI_Send(v_cadenas[i], 20, MPI_CHAR, 2, 0, MPI_COMM_WORLD);
            }
        }
    } else if (procesador == 1) {
        char cadena_recibida[20];
        for (int i = 0; i < n / 2 + n % 2; i++) {
            MPI_Recv(cadena_recibida, 20, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Procesador 1 (pares): %s\n", cadena_recibida);
        }
    } else if (procesador == 2) {
        char cadena_recibida[20];
        for (int i = 0; i < n / 2; i++) { 
            MPI_Recv(cadena_recibida, 20, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Procesador 2 (impares): %s\n", cadena_recibida);
        }
    }

    MPI_Finalize();

    
    return 0;
}
