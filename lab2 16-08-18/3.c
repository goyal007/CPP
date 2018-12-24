#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<limits.h>
int max=INT_MIN,min=INT_MAX;
int *arr;
int n;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_init(&lock,NULL);
void *func(void *arg)
{
    int i;
    for(i=0;i<n;i=i+2)//claculate even sum
    {
        pthread_mutex_lock(&lock);
        if(min>arr[i])
        	min=arr[i];
        if(max<arr[i])
        	max=arr[i];
        pthread_mutex_unlock(&lock);
    }
    return (NULL);    
}
main()
{
    int i;
    pthread_t thread;
    printf("Enter Number of element\n");
    scanf("%d",&n);    
    printf("fill array\n");
    arr=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
    }
    pthread_create(&thread,NULL,func,(void *)&n);
    for(i=1;i<n;i=i+2)//calculate odd sum
    {
        pthread_mutex_lock(&lock);
        if(min>arr[i])
        	min=arr[i];
        if(max<arr[i])
        	max=arr[i];
        pthread_mutex_unlock(&lock);
    }
    pthread_join(thread,NULL);
    printf("max number=%d\nmin number=%d \n",max,min);
}

