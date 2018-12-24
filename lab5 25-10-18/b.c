//mnit@mnit-OptiPlex-5040:~/Desktop$ mpicc 1.c
//mnit@mnit-OptiPlex-5040:~/Desktop$ mpirun -np 4 a.out
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
/* Run with two processes */
void main(int argc, char *argv[]) 
{
    int rank, i, count;
    float data[100],value[200];
    MPI_Status status;   
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(rank==1) 
    {
       for(i=0;i<100;++i) 
       {
			data[i]=i;
	   }
       MPI_Send(data,100,MPI_FLOAT,0,55,MPI_COMM_WORLD); 
    } 
    else 
    {
   	   MPI_Recv(value,200,MPI_FLOAT,MPI_ANY_SOURCE,55,MPI_COMM_WORLD,&status);
       printf("P:%d Got data from processor %d \n",rank,status.MPI_SOURCE);
       MPI_Get_count(&status,MPI_FLOAT,&count);
       printf("P:%d Got %d elements \n",rank,count);
       printf("P:%d value[5]=%f \n",rank,value[5]);
    }
    MPI_Finalize();
}
