#include <string.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int myrank, nprocs, namelen;
    char processorName[10];
    char data[12];


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Get_processor_name(processorName, &namelen);

    if (myrank == 0) { 
	strcpy(data, "Hello World");
         MPI_Send(data, 12, MPI_CHAR, 1, 888, MPI_COMM_WORLD);
	strcpy(data, "World Hello");
         MPI_Send(data, 12, MPI_CHAR, 1, 999, MPI_COMM_WORLD);

	}
else {

	MPI_Recv(data, 12, MPI_CHAR, 0, 999, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("processor %s having rank %d of %d received message: %s\n", processorName, myrank, nprocs, data);

}


    
    
    MPI_Finalize();
    return 0;
}
