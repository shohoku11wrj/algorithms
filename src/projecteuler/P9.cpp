#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	for (int i=1; i<332; i++)
	{
		for (int j=1; j<(999-i)/2; j++)
		{
			a=i;
			b=j;
			c=1000-a-b;
			if((a*a)+(b*b)==c*c) {
				cout<<a*b*c<<endl;	
			}
		}
	}
}
