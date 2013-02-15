#include <stdio.h>


void main()
{
	float s;
	float fac(int n);
	int num;
	printf("Input mathematics series number: \n");
	scanf("%d",&num);
	s=fac(num);
	printf("%-10.f\n",s);
}


float fac(int n)
{
	float p;
	if((n==0)||(n==1)) {
		p=1;
	} else {
		p=n*fac(n-1);
	}
	return p;
}
