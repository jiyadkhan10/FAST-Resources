/*
#include <stdio.h>
#define COUNT 5
int main(int argc, char** argv) {

int a[COUNT]={0,1,2,3,4};
int i;
for (i=0;i<COUNT-1;i++) {
    a[i] = a[i+1];
}
for (i=0;i<COUNT;i++) {
  printf("a[%d]:%d\n", i, a[i]);
}
  return 0;
}
*/

#include <stdio.h>
#include <omp.h>
#define COUNT 5
int main(int argc, char** argv) {

  int a[COUNT] = {0,1,2,3,4};
  int b[COUNT] = {0,1,2,3,4};

  int i;
  srand(time(NULL));
  #pragma omp parallel num_threads(COUNT)
  {
   #pragma omp for schedule(static, 1)
    for (i=0;i<COUNT-1;i++) {
      a[i] = b[i+1];
    }
  }
  for (i=0;i<COUNT;i++) {
    printf("a[%d]:%d\n", i, a[i]);
  }
    return 0;
}
