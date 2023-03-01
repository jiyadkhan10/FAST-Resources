#include <omp.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int threadData = 10;
    omp_set_num_threads(4);

    // Beginning of parallel region
    

     //#pragma omp parallel private(threadData)
     //#pragma omp parallel shared(threadData) 
     #pragma omp parallel private(threadData)
    {
        printf("Thread %d is Setting value...%d\n",omp_get_thread_num(),threadData);
        threadData =200;
    }

    // Ending of parallel region
    printf("Value: %d\n", threadData);
}


