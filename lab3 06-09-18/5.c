#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int ans=0;
void *f(void* val)
{
	int temp;
	temp=(int *)val;
	ans=ans+(temp*temp);
}
int main()
{
	int i,n;
	printf("Enter n\n");//n ->perfect sqaure
	scanf("%d",&n);
	pthread_t t[n];
	for(i=1;i*i<=n;i++)
	{
		pthread_create(&t[i],NULL,f,(void*)i);
	}
	for(i=1;i*i<=n;i++)
	{
		pthread_join(t[i],NULL);
	}
	printf("Sum of the series for given n=%d is %d\n",n,ans);
	return 0;
}
