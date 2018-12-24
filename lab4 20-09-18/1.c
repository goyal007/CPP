#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
sem_t semaphore; 
int common=0;
void* thread(void* arg) 
{ 
	char* msg=(char*)arg;
	while(1)
	{
		sem_wait(&semaphore); //waiting
		printf("\n%s-Entered critical section\n",msg);
		//int value;
	    //sem_getvalue(semaphore,value) ;
		//printf("%d\n",value);
		sleep(1);  //critical section
		common++;
		printf("\ncommon value-%d\n",common);
		printf("\n%s-Exiting critical section\n",msg); 
		sem_post(&semaphore); //signal
	}    
} 
int main() 
{ 
	sem_init(&semaphore,0,1); //binary semaphore
	pthread_t t1,t2; 
	char* msg1="Thread1";
	char* msg2="Thread2";
	pthread_create(&t1,NULL,thread,msg1); 
	sleep(3); 
	pthread_create(&t2,NULL,thread,msg2); 
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 
	sem_destroy(&semaphore); 
	return 0; 
}
//gcc a1.c -lpthread -lrt
