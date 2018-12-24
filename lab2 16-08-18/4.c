#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<limits.h>
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_init(&lock,NULL);
int *ans;
int sub;
float sum=0.0;
void *func(void *arg)
{
    int i;
    for(i=0;i<sub;i=i+2)//claculate even sum
    {
        pthread_mutex_lock(&lock);
        sum=sum+(float)ans[i];
         printf("in thread\n");
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);    
}
main()
{
    int n,i,id;
    char str[20];
    pthread_t thread;
    printf("Enter Name,ID,total subjects\n");
    scanf("%s%d%d",str,&id,&sub);    
    printf("enter marks\n");
    ans=(int *)malloc(sizeof(int)*sub);
    for(i=0;i<sub;i++)
    {
    	scanf("%d",&ans[i]);
	}
    pthread_create(&thread,NULL,func,NULL);
    for(i=1;i<sub;i=i+2)//calculate odd sum
    {
        pthread_mutex_lock(&lock);
        printf("in main\n");
       	sum=sum+(float)ans[i];
        pthread_mutex_unlock(&lock);
    }
    pthread_join(thread,NULL);
    printf("percentage of the student is::%f\n",(sum*1.0)/sub);
}


