#include <stdio.h>
#include <malloc.h>
#include <math.h>

int main(){
	//the number of real numbers to find the average for
	int i,n;
	scanf("%d",&n);

	double mean=0;
	double sum=0;

	double* data=malloc(sizeof(double)*n);
	for(i=0;i<n;++i){
		double f;
		scanf("%lf",&f);
		data[i]=f;
		sum+=f;
	}
	mean = sum/(double)n;

	double sumsquare = 0;
	double deviation;
	for(i=0;i<n;++i){
		deviation = data[i]-mean;
		sumsquare += deviation*deviation;
	}
	double variance = sumsquare/(double)n;
	double stddev = sqrt(variance);
	printf("Mean: %lf\nStddev %lf\n",mean,stddev);

	free(data);
	return 0;
}
