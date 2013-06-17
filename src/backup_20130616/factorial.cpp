#include <iostream>
#include <stdlib.h>

using namespace std;

int factorial(int n)
{
	if(n==0) {
		return 1;
	}
	else {
		return n*factorial(n-1);
	}
}

int main(int argc, char *argv[])
{
	if(argc==2) {
		int n = atoi(argv[1]);
		int result = factorial(n);
		cout<<result<<endl;
		return 0;
	}
	else {
		cout<<"Only one argument allowed."<<endl;
		return 1;
	}
}
