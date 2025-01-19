#include <mpi.h>
#include <stdio.h>
int main() {
	int n;
	int pid;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &n);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);

	if (pid == 0) {
		printf("I am the master .my pid is %d \n", pid);
	}
	else if(pid==1) {
		printf("I am the second master.my pid is %d \n", pid);
	}
	else {
		printf("I am the slave.my pid is %d \n", pid);
	}
	MPI_Finalize();
	return 0;
}