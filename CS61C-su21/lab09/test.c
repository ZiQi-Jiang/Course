#include<stdio.h>
#include<omp.h>
#include<time.h>
int a[10000],b[10000];
int main()
{
//   omp_set_num_threads(4);
	long long sum = 0;
	int MaxI = 10000;
	int times=10000;

	clock_t start = clock();
	for(int k=0;k<times;k++)
	{
		sum = 0;
	#pragma omp parallel
	{
		# pragma omp for
		for (int i = 0; i < MaxI; i++)
			sum += a[i]*b[i];
			
	//int num= omp_get_num_threads();
	//rintf("Thread Num:%d\n",num);
	}
	}
	clock_t end = clock();
	printf("Time Sum:%.4fs\n",(double)(end-start)/CLOCKS_PER_SEC);
	
	
}
