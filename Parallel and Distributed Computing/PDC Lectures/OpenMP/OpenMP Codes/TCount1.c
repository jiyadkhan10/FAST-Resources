#include <omp.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  int threadCount=0;
  #pragma omp parallel num_threads(10) 
  {

     //threadCount++;


     //change 1
    //int myLocalCount = threadCount; 
    //myLocalCount++;
    //threadCount = myLocalCount;

    //change 2
    int myLocalCount = threadCount; 
    sleep(1);
    myLocalCount++;
    threadCount = myLocalCount;


  }
  printf("Total Number of Threads: %d\n", threadCount);
}

