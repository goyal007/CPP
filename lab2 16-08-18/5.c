#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
struct employee
{
	char name[20];
	char id[20];
	char designation[20];
	int sal[5];
};
struct employee* emp;
void* func(void* a)
{
    pthread_mutex_lock(&mutex1);
    int temp= (int)a;
    float h;
    h = ((float)(emp->sal[temp] - emp->sal[temp-1])/(emp->sal[temp-1]))*100;
    pthread_mutex_unlock(&mutex1);
    return (void* )(int)(h);
}
int main()
{
	int i;
	void* ans;
	emp = (struct employee*)malloc(sizeof(struct employee));
	printf("Name-");
	scanf("%s",emp->name);
	printf("\nID-");
	scanf("%s",emp->id);
	printf("\nDesignation-");
    scanf("%s",emp->designation);
    printf("\nEnter salary of the last five years\n");
    for(i=0;i<5;i++)
    {
    	scanf("%d",&emp->sal[i]);
    }
    pthread_t thread[4];
    for(i=1;i<5;i++)
    {
    	pthread_create(&thread[i-1],NULL,func,(void*)i);
    }
    for(i=1;i<5;i++)
    {	
    	pthread_join(thread[i-1],&ans);
    	printf("Hike of %d%% in %d year\n",(int)ans,i);
    }
    return 0;
}
