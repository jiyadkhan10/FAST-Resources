#include <omp.h>
#include <stdio.h>
int main(int argc, char* argv[])
{ 

	const int size=20;
	int i, a[size];







	//#pragma omp parallel for schedule(static,3) num_threads(4)

	#pragma omp parallel for schedule(dynamic,2) num_threads(4)
	for (i=0; i<size;i++) { 
		a[i]=omp_get_thread_num(); 
		sleep(1); 
	}

	for (i=0; i<size;i++) 
		printf("%d\n",a[i]);
}
