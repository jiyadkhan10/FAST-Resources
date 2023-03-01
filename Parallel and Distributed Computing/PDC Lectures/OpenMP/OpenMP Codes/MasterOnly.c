#include <omp.h>
#include <stdio.h>

int main(int argc, char* argv[])
{

  int var=10; 
   omp_set_num_threads(4);

  #pragma omp parallel
  {
	printf("In parallel region, Thread no: %d\n",omp_get_thread_num());
	
	#pragma omp master 
        {
	       printf("In parallel/MASTER region, Thread no: %d\n",omp_get_thread_num()); 
	       var = var * 5;
	}
		
 }

 printf("Final value of var: %d \n",var);

}
