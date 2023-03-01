#include <omp.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
   int iam, nthreads;

   #pragma omp parallel private(iam,nthreads) num_threads(2)
    { 
       iam = omp_get_thread_num();
       nthreads = omp_get_num_threads(); 
       printf("ThradID %d, out of %d threads\n", iam, nthreads);

       if (iam==0)
          printf("Here is the Master Thread.\n");
      else
          printf("Here is another thread.\n");
   }

}
