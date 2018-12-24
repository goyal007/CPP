#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void* func(void *myvar)//function related to thread
{
    char* msg;
    msg=(char *) myvar;//as receive void, so type cast to message type
    printf("%s\n",msg);
    sleep(2);
}
int main(int argc,char* argv[])
{
    pthread_t thread1,thread2,thread3,thread4,thread5;//to create a thread_id
    char *msg1="first Thread";
    char *msg2="second Thread";
    char *msg3="third Thread";
    char *msg4="fourth Thread";
    char *msg5="fifth Thread";
    pthread_create(&thread1,NULL,&func,(void *)msg1);//it create a thread and starts its execution simultaneously with main func
    pthread_create(&thread2,NULL,&func,msg2);
    printf("after creating thread1 and 2\n");
    pthread_create(&thread3,NULL,&func,msg3);
    pthread_create(&thread4,NULL,&func,msg4);
    pthread_create(&thread5,NULL,&func,msg5);
    printf("all 5 threads are created\n");
    pthread_join(thread1,NULL);//join thread with main so that it completes its execution before main terminates
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    pthread_join(thread4,NULL);
    pthread_join(thread5,NULL);
    printf("have a nice day\n");
    return 0;
}
