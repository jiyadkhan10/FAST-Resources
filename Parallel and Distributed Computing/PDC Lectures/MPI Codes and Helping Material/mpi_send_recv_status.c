#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, recvdAmount;
    char data[] = "Hello";
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

if ( rank == 0) {
	MPI_Send(data, 6, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
	
}
else if (rank == 1) {
	MPI_Recv(data, 11, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status); 

   MPI_Get_count(&status, MPI_CHAR, &recvdAmount);

   printf("I am a slave process and I received %s from my master process\n”, data);
   printf("The status structure had source:%d, Tag:%d\n", status.MPI_SOURCE, status.MPI_TAG);
   printf("The number of elements received is :%d\n", recvdAmount); 
}
    MPI_Finalize();
    return 0;
}
