#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int myrank, nprocs, namelen;
    char processorName[10];


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Get_processor_name(processorName, &namelen);

    printf("Hello from process: %d waiting for others ... \n", myrank);
    MPI_Barrier(MPI_COMM_WORLD); 

    
    printf("I am running on  %s having rank %d of %d\n", processorName, myrank, nprocs);

    MPI_Finalize();
    return 0;
}
