#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 100000 // size of the queue(queue of product)
int queue[SIZE];
int tail,head; 
sem_t notfull,notempty;
void *producer(void *arg) 
{
	int val;
	do 
	{
		int val=rand()%100;
		printf("produced product number: %d\n",val);
	//	sem_wait(&notfull); /* wait for empty place in queue */
		queue[tail]=val; 
		tail=(tail+1)%SIZE;
		sem_post(&notempty); /* increment number of products in the queue */
		sleep(rand()%5); /* rest after product produce */
	}while(val);
}
void *consumer(void *arg)
{
	int val;
	do 
	{
	sem_wait(&notempty); /* wait for products in queue */
	val=queue[head]; 
	head=(head+1) % SIZE;
	printf("consumed product number: %d\n", val);
//	sem_post(&notfull); /* increase free spaces in the queue*/
	sleep(rand()%5); /* consume the product */
	}while(val); 
}
int main(int argc,char *argv[])
{
	pthread_t product,consume;
	sem_init(&notfull,0,SIZE); //middle zero means sharing b/w thread
	sem_init(&notempty,0,0);
	pthread_create(&product,NULL,producer,NULL);
	pthread_create(&consume,NULL,consumer,NULL);
	pthread_join(product,NULL);
	pthread_join(consume,NULL);
	sem_destroy(&notfull);
	sem_destroy(&notempty);
	return 0;
}
