#include <stdio.h>

void main()
{
	float fab(int n);

	int num;
	float result;
	printf("N of fabonacci series is: \n");
	scanf("%d",&num);
	result=fab(num);
	printf("Result is: %-16.f\n",result);
	 
}

float fab(int n)
{
	float sum;
	if(n==0) {
		sum=0;
	} else if(n==1) {
		sum=1;
	}
	else {
		sum=n+fab(n-1);
	}
	return sum;
}
