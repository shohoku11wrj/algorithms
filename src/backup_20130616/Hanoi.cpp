#include <iostream>

using namespace std;

void moveHanoi(int n, char source, char dest, char inter)
{
	if(n==1) {
		cout<<"Move disk from "<<source<<" to "<<dest<<endl;
	}
	else {
		moveHanoi(n-1,source,inter,dest);
		cout<<"Move disk from "<<source<<" to "<<dest<<endl;
		moveHanoi(n-1, inter, dest, source);
	}
}

int main()
{
	cout<<"This program solves the Towers of Hanoi problem"<<endl;
	cout<<"Enter the number of disks: ";
	int numberOfRings;
	cin>>numberOfRings;
	const char PEG_A = 'A', PEG_B='B', PEG_C='C';

	moveHanoi(numberOfRings, PEG_A, PEG_C, PEG_B);
}
