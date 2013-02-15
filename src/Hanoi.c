#include <stdio.h>

int main()
{
	void Hanoi(int n, char x, char y, char z);
	printf("How many scales the Hanoi has on X?\n");
	int n;
	scanf("%d",&n);
	Hanoi(n,'X','Y','Z');
	return 0;
}

void Hanoi(int n, char x, char y, char z)
{
	void move(char x, int m, char y);
	if(n==1) {
		move(x,1,z);
	} else {
		Hanoi(n-1,x,z,y);
		move(x,n,z);
		Hanoi(n-1,y,x,z);
	}
}

void move(char x, int m, char y)
{
	printf("move %d from %c to %c \n",m,x,y);
}
