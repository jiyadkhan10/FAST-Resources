#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank;
    char data[] = "Hello World";

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

if ( rank == 0) {
	MPI_Send(data, 12, MPI_CHAR, 1, 1234, MPI_COMM_WORLD);
}
else if (rank == 1) {
   MPI_Recv(data, 12, MPI_CHAR, 0, 1234, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
   printf("I am a slave and I received %s from my master\n", data);

}
    MPI_Finalize();
    return 0;
}
