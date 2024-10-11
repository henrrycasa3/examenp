#include "stdio.h"
#include "mpi.h"

#define MAXIMO 10

void main(int argc, char **argv) {
    int i;
    int vector1[MAXIMO], vector2[MAXIMO], vector3[MAXIMO], procesador;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador);

    if (procesador == 0) {
        int vector1[MAXIMO] = {1, 0, 3, 0, 5, 0, 7, 0, 9, 0};
        int vector2[MAXIMO] = {0, 2, 0, 4, 0, 6, 0, 8, 0, 10};

        MPI_Send(vector1, MAXIMO, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(vector2, MAXIMO, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(vector1, MAXIMO, MPI_INT, 2, 0, MPI_COMM_WORLD);
        MPI_Send(vector2, MAXIMO, MPI_INT, 2, 0, MPI_COMM_WORLD);

        for (i = 1; i < MAXIMO; i += 2) {
            MPI_Recv(&vector3[i], 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        for (i = 0; i < MAXIMO; i += 2) {
            MPI_Recv(&vector3[i], 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        for (i = 0; i < MAXIMO; i++) {
            printf("%d ", vector3[i]);
        }
        printf("\n");
    }

    if (procesador == 1) {
        MPI_Recv(vector1, MAXIMO, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(vector2, MAXIMO, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        for (i = 1; i < MAXIMO; i += 2) {
            vector3[i] = vector1[i] + vector2[i];
            MPI_Send(&vector3[i], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
    }

    if (procesador == 2) {
        MPI_Recv(vector1, MAXIMO, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(vector2, MAXIMO, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        for (i = 0; i < MAXIMO; i += 2) {
            vector3[i] = vector1[i] + vector2[i];
            MPI_Send(&vector3[i], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
}
