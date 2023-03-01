#include <stdio.h>
#include <omp.h>
#define COUNT 5
int main(int argc, char** argv) {

  int a[COUNT], b[COUNT];
  int i;
  #pragma omp parallel num_threads(COUNT)
  {
   #pragma omp for schedule(static, 1)
    for (i=0;i<COUNT;i++) {
      a[i] = i+1;
      b[i] = a[i]+1;
    }
  }
  for (i=0;i<COUNT;i++) {
    printf("a[%d]:%d b[%d]:%d\n", i, a[i], i, b[i]);
  }
    return 0;
}
