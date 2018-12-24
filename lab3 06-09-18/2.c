#include<stdio.h>
#include<stdlib.h>//for rand();
#include<pthread.h>
#define size 4
#define size_THREAD 4
int arrA[size][size];
int arrB[size][size];
int arrC[size][size];
int count = 0;
void* matrix(void* arg)
{
    int concurrent,i,j,k; 
    concurrent= count++;
    for(i=concurrent*size/4;i<(concurrent+1)*size/4;i++)
    {
        for(j=0;j<size;j++) 
	{
	      for(k=0;k<size;k++) 
	      {
       		arrC[i][j]+=arrA[i][k]*arrB[k][j];
	      }
	}
    }
}
int main()
{
    int i,j,k;
    for (i=0;i<size;i++) 
    {
        for (j=0;j<size;j++) 
	{
            arrA[i][j]=rand()%2;
            arrB[i][j]=rand()%2;
        }
    }
    printf("Matrix A\n");
    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < size; j++) 
            printf("%d ",arrA[i][j]);
        printf("\n");
    }
    printf("\nMatrix B\n");
    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < size; j++) 
            printf("%d ",arrB[i][j]);       
        printf("\n");
    }
    pthread_t threads[size_THREAD];
 
    for (i = 0; i < size_THREAD; i++) 
    {
        int* p;
        pthread_create(&threads[i], NULL, matrix, (void*)(p));
    }
    for (i = 0; i < size_THREAD; i++) 
        pthread_join(threads[i], NULL);    
    printf("\nMultiplication of A and B\n");
    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < size; j++) 
            printf("%d ",arrC[i][j]);       
        printf("\n");
    }
    return 0;
}
