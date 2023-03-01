#include <stdio.h>
#include <string.h>
#include "mpi.h"
int main(int argc, char **argv)
{
  char message[20], processorName[10];
  int  i, rank, size, nameLen;
  MPI_Status status;
  int root = 0;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(processorName, &nameLen);

  if (rank == root)
  {
    strcpy(message, "Hello, world");
}
MPI_Bcast(message, 13, MPI_CHAR, root, MPI_COMM_WORLD);
  
  printf( "%s:, Message from process %d : %s\n", processorName, rank, message);

  MPI_Finalize();
}
