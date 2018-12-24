#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int ans=0;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
void *func(void *arg)
{
    int *n,i;
    n=(int*)arg;
    for(i=2;i<=*n;i=i+2)//claculate even sum
    {
        pthread_mutex_lock(&lock);
        ans=ans+i;
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);    
}
main()
{
    int n,i;
    pthread_t thread;
    printf("Enter Natural Number\n");
    scanf("%d",&n);    
    pthread_create(&thread,NULL,func,(void *)&n);
    for(i=1;i<=n;i=i+2)//calculate odd sum
    {
        pthread_mutex_lock(&lock);
        ans=ans+i;
        pthread_mutex_unlock(&lock);
    }
    pthread_join(thread,NULL);
    printf("Sum of first %d natural numbers=%d \n",n,ans);
}


