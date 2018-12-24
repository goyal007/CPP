#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void* func(void *myvar)
{
    printf("Hello World............\n");
    sleep(1);
}
int main(int argc,char* argv[])
{
    pthread_t thread1;
    pthread_create(&thread1,NULL,&func,NULL);
    printf("thread is created\n");
    pthread_join(thread1,NULL);
    printf("have a nice day\n");
    return 0;
}
