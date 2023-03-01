#include <omp.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	srand(time(NULL));
	int winner; 
	#pragma omp parallel reduction(max:winner) num_threads(5)
	{ 
		winner = (rand() % 1000) + omp_get_thread_num(); 
 		printf("Thread: %d has Chosen: %d\n", omp_get_thread_num(),winner);
	}
	
	printf("Winner: %d\n", winner);
}
