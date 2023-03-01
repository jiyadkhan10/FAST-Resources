#include <omp.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
   //int v=5;
   printf("Hello World... at START= %d\n", omp_get_thread_num());

   #pragma omp parallel num_threads(4)
   {
      printf("Hello World... from thread = %d\n", omp_get_thread_num());
      int id=omp_get_thread_num();
      if (id==1)
       printf("Hello World PDC\n");
   }

   printf("Hello World... from MASTER = %d\n", omp_get_thread_num());
}

