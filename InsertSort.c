#include <iostream.h>

using namespace std;
#define MAXSIZE 100;

typedef struct
{
	int key;
} node;

node r[100];

void bubsort(node r[], int n);

int main()
{
	int i=0,n;
	cout<<"Input the unsorted series:3\n4\n5\n6\n-999\n"<<endl;
	int input;
	cin>>input;
	while(1)
	{
		if(input==-999)
		{
			r[i].key=-999;
			break;
		}
		r[i].key=input;
		i++;
		cin>>input;
	}

	n=i-1; //-999 cannot be incluided in counting n, or the output result would be blank.
	cout<<"n="<<n<<endl;

	int cmd;
	do{
		cout<<"Sort by(1-bubsort 4-print 5-exit): ";
		cin>>cmd;
		switch(cmd)
		{
			case 1: bubsort(r,n);
					break;
			case 4:
					{
						printf("The sorted series is:\n");
						for(i=1;i<=n;i++)
						{
							cout<<r[i].key<<" ";
						}
						cout<<endl;
					}
					break;
			case 5:
					exit(0);
			default:
					break;
		}
	} while(cmd<6);

}

void bubsort(node r[], int n)
{
	int temp,i,j,tag=1;
	for(i=0;i<=n;i++)
	{
		if(tag==0){
			break;
		}
		tag=0;
		for(j=n;j>i;j--)
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
