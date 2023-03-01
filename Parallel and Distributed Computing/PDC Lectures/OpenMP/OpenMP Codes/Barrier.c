#include <omp.h>
#include <stdio.h>

int main(int argc, char* argv[])
{

   omp_set_num_threads(5);

  #pragma omp parallel
  {
	printf("Before Barrier, Thread Arrived at Barrier: %d\n",omp_get_thread_num());
	
        //#pragma omp barrier 
	printf("Afetr Barrier, Thread Resumed: %d\n",omp_get_thread_num());	
  }

}
