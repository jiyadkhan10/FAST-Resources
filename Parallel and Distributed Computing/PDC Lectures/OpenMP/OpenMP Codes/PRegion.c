#include <omp.h>
#include <stdio.h>

int main(int argc, char* argv[])
{


  omp_set_num_threads(2);

  #pragma omp parallel
  {
     if(omp_in_parallel())
	printf("Thread no: %d is executing in PARALLEL region\n",omp_get_thread_num());
     else
	printf("Thread no: %d is executing in SERIAL region\n",omp_get_thread_num());
  }


   if(omp_in_parallel())
	printf("Thread no: %d is executing in PARALLEL region\n",omp_get_thread_num());
   else
        printf("Thread no: %d is  executing in SERIAL region\n",omp_get_thread_num());

}
