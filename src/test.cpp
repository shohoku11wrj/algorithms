#include <iostream>
using namespace std;

void nyear(int n)
{
	long double multiplier = 1;
	long double multiplier2 = 1;
	for(int i=0; i<365*n; i++)
	{
		multiplier*=1.01;
		multiplier2*=0.99;
	}
	multiplier*=100;
	multiplier2*=100000000;

	cout<<"100 * 1.01/day * "<<n<<"year = " <<multiplier<<endl;
	cout<<"100000000 * 0.99/day * "<<n<<"year = " << multiplier2<<endl;
	cout<<endl;
}

int main()
{
	nyear(1);
	nyear(2);
	nyear(4);
	nyear(8);

	return 1;
}
