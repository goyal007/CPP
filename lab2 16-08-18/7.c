#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
int arr[10][10];
int l,m,sum=0,total;
int counter=-1;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
void* func(void* arg)
{
 	pthread_mutex_lock(&lock);
    int i;
    counter++;
	total=0;
    for(i=0;i<m;i++)
    {
    	total+=arr[counter][i];
	}
	sleep(1);
	sum+=total;
     printf("%d\n",sum);
   // sleep(1);
    pthread_mutex_unlock(&lock);
    return NULL;
}
int main(int argc,char* argv[])
{
    int i,j;
    printf("enter row and column\n");
    scanf("%d %d",&l,&m);
    printf("fill array\n");
    for(i=0;i<l;i++)
    for(j=0;j<m;j++)
    	scanf("%d",&arr[i][j]);
    pthread_t thread[l];
    for(i=0;i<l;i++)
    {
	
    pthread_create(&thread[i],NULL,&func,NULL);

    }
   // printf("%d\n",sum);
    for(i=0;i<l;i++)
    pthread_join(thread[i],NULL);
	 printf("sum is=%d\n",sum);
    return 0;
}
/*
1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 
*/
