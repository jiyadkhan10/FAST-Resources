#include <omp.h>
#include <stdio.h>

int Fun(int id, int A[])
{
  int sum=0; int i=0;
  for(i=0;i<10;i++)
     sum+=A[i];

  printf("Thread %d calculated sum=%d\n",id,sum);
  return 0;
}


int main(int argc, char* argv[])
{

  int A[10]={0,1,2,3,4,5,6,7,8,9};

  omp_set_num_threads(10);

  #pragma omp parallel
  {
   int ID = omp_get_thread_num();
   if(ID==7)
	A[0]=20;
   Fun(ID,A);
  }

  printf("Thread %d is the last thread and A[0] is %d\n",omp_get_thread_num(),A[0]);

}
