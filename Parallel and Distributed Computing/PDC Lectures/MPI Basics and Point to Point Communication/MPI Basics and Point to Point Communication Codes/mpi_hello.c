#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int myrank, nprocs, namelen;
    char processorName[10];


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Get_processor_name(processorName, &namelen);

if (myrank == 0) {
  printf("\n\nHello from process 0\n\n");

}
else {
  printf("Hello from some other process\n");

}

    MPI_Finalize();
    return 0;
}
