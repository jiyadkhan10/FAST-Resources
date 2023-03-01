#include <omp.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  int threadCount=0;
  #pragma omp parallel num_threads(1000) 
  {
    #pragma omp critical
     {
       //int myLocalCount = threadCount; 
       //sleep(1);
      // myLocalCount++;
       threadCount++; //= myLocalCount;
    }

  }
  printf("Total Number of Threads: %d\n", threadCount);
}

