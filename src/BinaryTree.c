#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node *lch, *rch;
} Bnode;

Bnode *s[10];
Bnode *q;
int j,top,boo;

Bnode  *Create();
void TLR_recur(Bnode *p);
void TLR(Bnode *p);
void LTR_recur(Bnode *p);
void LTR(Bnode *p);
void LRT_recur(Bnode *p);
void LRT(Bnode *p);

void main()
{ 
	Bnode *Head;
	int cmd;
	do{
		printf("1-Create 2-TLR_recursive 3-LTR_recur 4-LRT_recur 5-TLR 6-LTR 7-LRT 8-Quit: ");
		scanf("%d",&cmd);
		switch(cmd)
		{
			case 1:
				Head=Create();
				printf("\n");
				break;
			case 2:
				TLR_recur(Head);
				printf("\n");
				break;
			case 3:
				LTR_recur(Head);
				printf("\n");
				break;
			case 4:
				LRT_recur(Head);
				printf("\n");
				break;
			case 5:
				TLR(Head);
				printf("\n");
				break;
			case 6:
				LTR(Head);
				printf("\n");
				break;
			case 7:
				LRT(Head);
				printf("\n");
				break;
			case 8:
				exit(0);
			default:
				break;
		}
	} while(cmd<=8);
	Head=Create();
}

Bnode  *Create()
{
	int i;
	ElemType x;
	Bnode *t=NULL;
	printf("\n i,x=");
	scanf("%d,%c",&i,&x);
	while((i!=0)&&(x!=0))
	{
		q=(struct node*) malloc(sizeof(struct node));
		q->data=x;
		q->lch=NULL;
		q->rch=NULL;
		s[i]=q;
		if(i==1) {
			t=q;
		}
		else {
			j=i/2;
			if((i%2)==0) {
				s[j]->lch=q;
			} else {
				s[j]->rch=q;
			}
		}
		printf("\n i,x=");
		scanf("%d,%c",&i,&x);
	}
	return t;
}

void TLR_recur(Bnode *p)
{
	if(p!=NULL)
	{
		printf("%c ",p->data);
		TLR_recur(p->lch);
		TLR_recur(p->rch);
	}
}

void TLR(Bnode *p)
{
	q=p;
	top=0; //Top of Linear Stack
	boo=1; //bool==1 -> do while, bool==0 -> stop loop
	do
	{
		while(q!=NULL)
		{
			top++;
			s[top]=q;
			printf("%c ",q->data);
			q=q->lch;
		}
		if(top==0) {
			boo=0;
		} else {
			q=s[top];
			top--;
			q=q->rch;
		}
	} while(boo);
	printf("\n");
}

void LRT_recur(Bnode *p)
{
	if(p!=NULL)
	{
		LRT_recur(p->lch);
		LRT_recur(p->rch);
		printf("%c ",p->data);
	}
}

void LRT(Bnode *p)
{
	int s2[20];
	q=p;
	top=0; //Top of Linear Stack
	boo=1; //bool==1 -> do while, bool==0 -> stop loop
	do
	{
		while(q!=NULL)
		{
			top++;
			s[top]=q;
			q=q->lch;
			s2[top]=1;
		}
		if(top==0) {
			boo=0;
		} else {
			if(s2[top]==1)
			{
				q=s[top];
				q=q->rch;
				s2[top]=2;
			}
			else
			{
				q=s[top];
				s2[top]=0;
				top--;
				printf("%c ",q->data);
				q=NULL; //** I miss it.
			}
		}
	} while(boo);
}

void LTR_recur(Bnode *p)
{
	if(p!=NULL)
	{
		LTR_recur(p->lch);
		printf("%c ",p->data);
		LTR_recur(p->rch);
	}
}

void LTR(Bnode *p)
{
	q=p;
	top=0; //Top of Linear Stack
	boo=1; //bool==1 -> do while, bool==0 -> stop loop
	do
	{
		while(q!=NULL)
		{
			top++;
			s[top]=q;
			q=q->lch;
		}
		if(top==0) {
			boo=0;
		} else {
			q=s[top];
			top--;
			printf("%c ",q->data);
			q=q->rch;
		}
	} while(boo);
	printf("\n");
}
