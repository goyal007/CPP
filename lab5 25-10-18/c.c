//mnit@mnit-OptiPlex-5040:~/Desktop$ mpicc 1.c
//mnit@mnit-OptiPlex-5040:~/Desktop$ mpirun -np 4 a.out
#include <mpi.h>
#include <stdio.h>
int main(int argc, char** argv) 
{
	int rank;
	int buffer;
	const int root=0;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank == root) 
	{
		buffer=111;
	}
	printf("[%d]: Before Broadcast, buffer is %d\n", rank, buffer);
	/* everyone calls bcast, data is taken from root and ends up in everyone's buffer */
	MPI_Bcast(&buffer, 1, MPI_INT, root, MPI_COMM_WORLD);
	printf("[%d]: After Broadcast, buffer is %d\n", rank, buffer);
	MPI_Finalize();
	return 0;
}
