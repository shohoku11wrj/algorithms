#include <stdio.h>

#define MAXSIZE 100;

typedef struct
{
	int key;
} node;

node r[100];

void stinsort(node r[], int n);
void binasort(node r[], int n);
void shellsort(node r[], int n);

int main()
{
	int i=1,n;
	printf("Input the unsorted series:3\n4\n5\n6\n-999\n");
	int input;
	scanf("%d",&input);
	while(1)
	{
		if(input==-999)
		{
			r[i].key=-999;
			break;
		}
		r[i].key=input;
		i++;
		scanf("%d",&input);
	}

	n=i-1; //-999 cannot be incluided in counting n, or the output result would be blank.
	printf("n=%d\n",n);

	int cmd;
	do{
		printf("Sort by(1-stinsort 2-binasort 3-shellsort 4-print 5-exit): ");
		scanf("%d",&cmd);
		switch(cmd)
		{
			case 1: stinsort(r,n);
					break;
			case 2: binasort(r,n);
					break;
			case 3: shellsort(r,n);
					break;
			case 4:
					{
						printf("The sorted series is:\n");
						for(i=1;i<=n;i++)
						{
							printf("%d,",r[i].key);
						}
						printf("\n");
					}
					break;
			case 5:
					exit(0);
			default:
					break;
		}
	} while(cmd<6);

}

void stinsort(node r[], int n)
{
	int i,j;
	for(i=2;i<=n; i++)
	{
		r[0]=r[i];
		j=i-1;
		while(r[j].key>r[0].key)
		{
			r[j+1]=r[j];
			j--;
		}
		r[j+1]=r[0];
	}

}

void binasort(node r[], int n)
{
	int mid,l,h;
	for(int i=2;i<=n;i++)
	{
		r[0]=r[i];
		l=1;
		h=i-1;
		while(l<=h) //WHY l<=h? =?
		{
			mid=(l+h)/2;
			if(r[0].key<r[mid].key) {
				h=mid-1;
			} else {
				l=mid+1;
			}
		}
		for(int j=i-1;j>=l;j--){
			r[j+1]=r[j];
		}
		r[l]=r[0];
	}
}

void shellsort(node r[], int n)
{
	int k,i,j;
	k=n/2;
	while(k>=1)
	{
		for(i=k+1;i<=n;i++)
		{
			r[0]=r[i];
			j=i-k;
			while((r[j].key>r[0].key)&&(j>=0))
			{
				r[j+k]=r[j];
				j=j-k;
			}
			r[j+k]=r[0];
		}
		k=k/2;
	}
}
