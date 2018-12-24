#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int fib[10000];
int prime[10000];
int num,ind=0;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2=PTHREAD_MUTEX_INITIALIZER;
void* func(void *a)
{
	pthread_mutex_lock(&mutex1);
	fib[0]=0;
	fib[1]=1;
	int i;
	for(i=2;i<num;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		
	}
	pthread_mutex_unlock(&mutex1);
}
void* func1(void *a)
{
	pthread_mutex_lock(&mutex2);
	int i,j;
	for(i=1; i<=num; i++)
    {
        int fact=0;
        for(j=1; j<=i; j++)
        {
            if(i%j==0)
                fact++;
        }
        if(fact==2)
        {
        	prime[ind]=i;
        	ind++;
		}      
    }
    pthread_mutex_unlock(&mutex2);
}
int main()
{
	int i;
    pthread_t thread1,thread2;
    printf("enter the number\n");
   	scanf("%d",&num);
    pthread_create(&thread1,NULL,func,NULL);
    pthread_create(&thread2,NULL,func1,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("Fibonacci series for the given number is:: ");
    for(i=0;i<num;i++)
    {
    	printf("%d ",fib[i]);
    }
    printf("\n");
    printf("Prime Number Series for the given number is:: ");
    for(i=0;i<ind;i++)
    {
    	printf("%d ",prime[i]);
    }
    printf("\n");
    return 0;
}
