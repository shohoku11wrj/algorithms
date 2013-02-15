#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
#define MAXSIZE 100;

typedef struct
{
	int key;
} node;

node r[100];

int readArray(node []);
void bubsort(node [], int); // in declaration, the arguments names could be omited.
int hoare(node r[], int l, int h);
void quicksort_recur(node r[], int l, int h);
void quicksort(node r[], int n);
template <class T> 
void swap2(T &a1, T &a2); // swap is existed in std lib, so name it another 
void bubbleSort2(node A[], int size);


int main()
{
	int i=0,n;
	/*
	   cout<<"Input the unsorted series:3\n4\n5\n6\n-999\n"<<endl;
	cin>>r[i].key;
	while(1)
	{
		if(r[i].key==-999)
		{
			break;
		}
		i++;
		cin>>r[i].key;
	}

	n=i; //-999 cannot be incluided in counting n, or the output result would be blank.
	*/
	n=readArray(r);
	cout<<"n="<<n<<endl;

	int cmd;
	do{
		cout<<"Sort by(1-bubsort 2-quicksort_recur 3-quicksort 4-print 5-exit 6-bubbleSort2): ";
		cin>>cmd;
		switch(cmd)
		{
			case 1: bubsort(r,n);
					break;
			case 2:
					quicksort_recur(r,0,n-1);
					break;
			case 3:
					quicksort(r,n-1);
					break;
			case 4:
					{
						cout<<"The sorted series is:"<<endl;
						for(i=0;i<n;i++)
						{
							cout<<r[i].key<<" ";
						}
						cout<<endl;
					}
					break;
			case 5:
					exit(0);
			case 6:
					bubbleSort2(r,n);
					break;
			default:
					break;
		}
	} while(cmd<7);

}

void bubsort(node r[], int n)
{
	int temp,i,j,tag=1;
	for(i=0;i<n;i++)
	{
		if(tag==0){
			break;
		}
		tag=0;
		for(j=n-1;j>i;j--)
		{
			if(r[j].key<r[j-1].key) {
				temp=r[j-1].key;
				r[j-1].key=r[j].key;
				r[j].key=temp;
				tag=1;
			}
		}
	}
}

template <class T> 
void swap2(T &a1, T &a2)
{
	T temp=a1;
	a1=a2;
	a2=temp;
}

void bubbleSort2(node A[], int size)
{
	if ( size <= 1) return;
	int pass = 0;
	int swapCount, below, above;
	do {
		swapCount = 0;
		for (below = size-1, above = size-2; above >= pass; below--, above--) {
			if ( A[below].key < A[above].key ) {
				swap( A[below], A[above]);
				swapCount++;
			} // end if
		} // end for
		pass++;
	} while ( swapCount > 0 && pass < size - 1);
} // end function bubbleSort

int hoare(node r[], int l, int h) // l-first, h-last
{
	int i=l;
	int j=h;
	node x=r[i];
	do{
		while((i<j)&&r[j].key>=x.key) {
			j--;
		}
		if(i<j) {
			r[i]=r[j]; // at this time, r[i] is valueless
			i++;
		}
		while((i<j)&&r[i].key<x.key) {
			i++;
		}
		if(i<j) {
			r[j]=r[i]; // at this time, r[j] is valueless since the original r[j] had been changed to r[i]
			j--;
		}
	} while(i<j);
	r[i]=x;
	return i;
}

void quicksort_recur(node r[], int l, int h)
{
	int i;
	if(l<h)
	{
		i=hoare(r,l,h);
		quicksort_recur(r,l,i-1);
		quicksort_recur(r,i+1,h);
	}
}

void quicksort(node r[], int n)
{
	int l=0; // the 1st hoare use r[0] for standard
	int h=n;
	int tag=1; // when the stack is empty ==> tag=0
	int top=0; // top of stack
	int s[n][2]; // stack, store the l and h of right laft of r[]
	int i;
	do{
		while(l<h) {
			i=hoare(r,l,h);
			top++;
			s[top][0]=i+1;
			s[top][1]=h;
			h=i-1;
		} // finish all the sort before i
		if(top==0) {
			tag=0;
		} else {
			l=s[top][0];
			h=s[top][1];
			top--;
		} // get l and h after i, and then to do the sort after i
		
	} while(tag==1);
	
}

int readArray(node r[])
{
	int size,i;
	ifstream in("input.dat");
	for(i=0;i<100;i++)
	{
		in>>r[i].key;
		if(r[i].key==-999){
			break;
		}
	}
	size=i;
	return size;
}
