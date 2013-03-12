#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int a,b,c,sum;
	for(a=1; a<32; a++) {
		for(b=1; b<32; b++) {
			int c2 = a*a + b*b;
			float d = sqrt(c2);
			int c = sqrt(c2);
			if(d-c>0) {
				continue;
			}
			sum = a+b+c;
			if(1000%sum==0) {
				int m = 1000/sum; // multiper
				int result=a*b*c*m*m*m;
				cout<<a*m<<" "<<b*m<<" "<<c*m<<" "<<result<<endl;
				return(1);
			}
		}
	}
	cout<<"no"<<endl;
	return(0);
}
