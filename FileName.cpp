#include <mpi.h>
#include <stdio.h>         

int main() {
	int n;
	int pid;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &n);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	MPI_Status sta;

	if (pid == 0) {
		int msg = 2;
		for (int i = 1; i < n; i++) {
			MPI_Send(&msg, 1, MPI_INT, i, 50, MPI_COMM_WORLD);
		}
		printf("My processor id is %d,Im the sender,The msg is %d \n", pid, msg);
	}
	else {
		int Rec_msg;
		MPI_Recv(&Rec_msg, 1, MPI_INT, 0, 50, MPI_COMM_WORLD, &sta);
	}
}