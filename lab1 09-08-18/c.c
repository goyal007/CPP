#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
double *arr;
void* func(void *myvar)
{
    int i;
   arr=(double *)malloc(sizeof(double)*100);
    for(i=0;i<100;i++)
    {
        double temp;
        temp=(double)sqrt(i);
        arr[i]=temp;
    }
    return ((void *)arr);
}
int main(int argc,char* argv[])
{
    void * temp;//for holding returned result
	// void * temp;//for holding returned result    
    int i;
    pthread_t thread1;
    pthread_create(&thread1,NULL,&func,NULL);
    pthread_join(thread1,&temp); //here it is returned
    arr=(double *)temp;
    //pthread_join(thread1,NULL); //here it is returned
    //arr=(double *)temp;
    for(i=0;i<100;i++)
    {
         printf("root of %d is %lf\n",i,arr[i]);
    }
    return 0;
}
