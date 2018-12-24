#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h>
sem_t semphore;
int common=0;
void* thread(void* arg) 
{ 
	int message=(int)arg;
	while(1)
	{
		sem_wait(&semphore); 
		printf("\nThread %d-Entered critical section\n",message);   
		sleep(3); 
		common++;
		printf("\ncommon value-%d\n",common);
		printf("\nThread %d-Exiting critical section\n",message); 
		sem_post(&semphore); 
	}    
} 
int main() 
{ 
	sem_init(&semphore,0,1); 
	pthread_t thr[10];
	int i;
	for(i=0;i<10;i++)
	{
		pthread_create(&thr[i],NULL,thread,i); 
		sleep(2);
	}
	for(i=0;i<10;i++)
	{
		pthread_join(thr[i],NULL);        
	}    
	sem_destroy(&semphore); 
	return 0; 
}
