#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv) {


  MPI_Init(NULL, NULL);

  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size, nameLen;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  char sendersData[13], processorName[10];
  char recvrsData[2];
  MPI_Get_processor_name(processorName, &nameLen);


  if (world_rank == 0) {
	strcpy(sendersData,"Hello World!");
   }


  MPI_Scatter(sendersData, 1, MPI_CHAR, recvrsData,
              1, MPI_CHAR, 0, MPI_COMM_WORLD);

  printf("I am: %s, My Data is: %c\n", processorName, recvrsData[0]);






  MPI_Finalize();
}
