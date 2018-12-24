//mnit@mnit-OptiPlex-5040:~/Desktop$ mpicc 1.c
//mnit@mnit-OptiPlex-5040:~/Desktop$ mpirun -np 4 a.out

#include <mpi.h>
#include<stdio.h>
main(int argc, char *argv[])
{
	//current value of time
	
	
	int npes, myrank;
	// Initialize the MPI environment
	MPI_Init(&argc, &argv);
	// Get the number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &npes);
	// Get the rank of the process
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	float a1=MPI_Wtime();
	printf("start time for process %d is=%f\n\n",myrank,a1);
	printf("From process %d out of %d,Hello World!\n\n", myrank, npes);
	// Finalize the MPI environment.
	float a2=MPI_Wtime();
	printf("end time for process %d is=%f\n\n",myrank,a2);
	
	MPI_Finalize();
}
