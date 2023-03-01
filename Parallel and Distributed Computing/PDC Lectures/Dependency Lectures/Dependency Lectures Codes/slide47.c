
#include <stdio.h>
#include <omp.h>
#define COUNT 3
int main(int argc, char** argv) {

  int a[COUNT][COUNT]={{0,1,2},{0,1,2},{0,1,2}};
  int i,j;

  #pragma omp parallel num_threads(COUNT)
  {
   #pragma omp for schedule(static, 1)
   for (i=0; i<COUNT; i++) {
    for (j=0; j<COUNT-1; j++) {
     a[i][j+1] = a[i][j] + 10;
     //printf("Thread id:%d Total Threads:%d\n",omp_get_num_thread(),omp_get_num_threads());
     }
   }
  }
  for (i=0; i<COUNT; i++) {
   for (j=0; j<COUNT; j++) {
    printf("a[%d][%d]:%d\n", i,j,a[i][j]);
    }
  }
    return 0;
}
