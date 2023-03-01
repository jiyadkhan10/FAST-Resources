#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int size, rank, i, returnval, localSum, globalSum, nameLength;
    int *inputdata =NULL;
    int *gatherdData =NULL;

    int localdata[2];

    char processorName[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(processorName, &nameLength);



    if (rank == 0) {
        inputdata = malloc(size*2 * sizeof(int) );
        gatherdData = malloc(size * sizeof(int) );

	printf("Please enter %d numbers!\n", size*2);
        for (i=0; i<size*2; i++)
            returnval = scanf("%d", &inputdata[i]);

        printf("Process having rank: %d, running on Processor: %s has data: ", rank, processorName);
        for (i=0; i<size*2; i++)
            printf("%d ", inputdata[i]);
        printf("\n");
    }

    MPI_Scatter(inputdata, 2, MPI_INT, localdata, 2, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d: has data %d and %d\n", rank, localdata[0], localdata[1]);
    localSum = localdata[0] + localdata[1];
    printf("Process %d: summed the data, now has %d\n", rank, localSum);

    MPI_Gather(&localSum, 1, MPI_INT, gatherdData, 1, MPI_INT, 0, MPI_COMM_WORLD);

    globalSum = 0;
    if (rank == 0) {
        printf("Process %d has data: ", rank);
        for (i=0; i<size; i++) {
            printf("%d ", gatherdData[i]);
	    globalSum+= gatherdData[i];

	}
        printf("\nThe summed up data is %d\n", globalSum);
    }

    if (rank == 0)
        free(inputdata);
	free(gatherdData);

    MPI_Finalize();
    return 0;
}
