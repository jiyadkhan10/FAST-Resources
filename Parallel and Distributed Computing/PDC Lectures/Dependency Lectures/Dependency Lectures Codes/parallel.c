#include <stdio.h>
#include <mpi.h>
#include <omp.h>

int TaskX() {
  sleep(15);
  return 15;
}
int TaskY() {
  sleep(5);
  return 5;
}
int TaskZ() {
  sleep(5);
  return 5;
}

int main(int argc, char** argv) {
    int myrank, nprocs;
    int x,y;
    int z=10;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);


    switch(myrank){
      case 1:
        x=TaskX();
        MPI_Send(&x,1,MPI_INT,0,787,MPI_COMM_WORLD);
        break;
      case 2:
        y=TaskY()+z;
        MPI_Send(&y,1,MPI_INT,0,787,MPI_COMM_WORLD);
        break;
      case 3:
        y=x-5;
        MPI_Send(&y,1,MPI_INT,0,787,MPI_COMM_WORLD);
        break;
      case 4:
        z=TaskZ();
        MPI_Send(&z,1,MPI_INT,0,787,MPI_COMM_WORLD);
        break;
    }


    if (myrank == 0) {
      MPI_Status status;
      int recvdValue,i;
      for (i=1;i<5;i++) {
        MPI_Recv(&recvdValue, 1, MPI_INT, MPI_ANY_SOURCE, 787, MPI_COMM_WORLD, &status);
        switch(status.MPI_SOURCE){
          case 1:
            x=recvdValue;
            break;
          case 2:
            y=recvdValue;
            break;
          case 3:
            y=recvdValue;
            break;
          case 4:
            z=recvdValue;
            break;
        }
        printf("Received: %d From: %d\n", recvdValue,status.MPI_SOURCE );

      }
      printf("x: %d y: %d z: %d\n", x, y, z);

    }
    MPI_Finalize();
    return 0;
}
