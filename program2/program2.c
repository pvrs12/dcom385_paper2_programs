#include <stdio.h>
#include <math.h>
#include <malloc.h>

int main(){
	int i,n;
	scanf("%d",&n);

	double* x_data=malloc(sizeof(double)*n);
	double* y_data=malloc(sizeof(double)*n);

	double xsum=0;
	double ysum=0;
	for(i=0;i<n;++i){
		double x,y;
		scanf("%lf%lf",&x,&y);
		x_data[i]=x;
		y_data[i]=y;
		xsum+=x;
		ysum+=y;
	}
	double xmean=xsum/(double)n;
	double ymean=ysum/(double)n;
	
	double xsumsquare=0;
	double ysumsquare=0;

	double xdev;
	double ydev;

	double cov = 0;
	for(i=0;i<n;++i){
		xdev = x_data[i]-xmean;
		ydev = y_data[i]-ymean;

		xsumsquare += xdev*xdev;
		ysumsquare += ydev*ydev;

		cov += xdev*ydev;
	}
	cov *= 1./(double)(n-1);

	double xvar = xsumsquare/(double)n;
	double yvar = ysumsquare/(double)n;

	double xstd = sqrt(xvar);
	double ystd = sqrt(yvar);
	
	double slope = (ystd*cov)/(xstd);
	double inter = (cov*xmean)/(xstd)+ymean;

	printf("y = %.2lfx + %.2lf\n",slope,inter);
	return 0;
}
