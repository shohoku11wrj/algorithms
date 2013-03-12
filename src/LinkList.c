#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *next;
}Lnode;

Lnode *h,*p,*q,*ptr;

void Initiate(Lnode *head)
{
	head->next=NULL;
}

ElemType x;
void create(Lnode *head)
{
	//head=(Lnode *) malloc (sizeof(Lnode));
	Initiate(head); //head->next=NULL;
	p=head;
	printf("x=?"); scanf("%d",&x);
	while(x!=-999)
	{
		ptr=(Lnode *) malloc(sizeof(Lnode));
		ptr->data=x;
		ptr->next=NULL;
		p->next=ptr;
		p=ptr;
		printf("x=?"); scanf("%d",&x);
	}
}

void printLnode(Lnode *head)
{
	Lnode *node;
	printf("This LinkNode is: ");
	node=head;
	while(node->next!=NULL)
	{
		node=node->next;
		printf("%d ",node->data);
	}
	printf("\n");
}

void delete(Lnode *head, ElemType x)
{
	q=head;
	p=q->next;
	while((q!=NULL)&&(p->data!=x))
	{
		q=p;
		p=p->next;
	}
	if(p==NULL) {
		printf("NO!\n");
	} else {
		q->next=p->next;
		free(p);
		printf("YES!\n");
	}
}

void insertNode(Lnode *head, int i, ElemType y); //Declaration of insertNode.
void inverse(Lnode *head);
void inversePrint_Recur(Lnode *head);

void command(Lnode *head)
{
	printf("Input command number: 1-Delete 2-Insert 3-Print 4-Quit 5-Inverse 6-InversePrint_Recur\n");
	int cmd;
	scanf("%d",&cmd);
	switch(cmd)
	{
		case 1: 
			printf("Which data would you delete?\n");
			ElemType data;
			scanf("%d",&data);
			delete(head,data); 
			break;
		case 2:
		{ 
		    int pos;
			ElemType val;
			printf("Insert position and value: k,v\n");
			scanf("%d,%d",&pos,&val);
			insertNode(head,pos,val);
			break;
		}
		case 3: printLnode(head); break;
		case 4: printf("Quit\n"); break;
		case 5: inverse(head); break;
		case 6: inversePrint_Recur(head->next); printf("\n"); break;
		default: break;
	}
	if(cmd!=4)
	{
		command(head);
	}
}

void insertNode(Lnode *head, int i, ElemType y)
{
	int k=0;
	p=head;
	Lnode *s;
	while((p->next!=NULL)&&(k<i-1))
	{
		p=p->next;
		k++;
	}
	if(k==i-1) {
		s=(Lnode *) malloc(sizeof(Lnode));
		s->data=y;
		s->next=p->next;
		p->next=s;
	} else {
		printf("\nInsert position error!\n");
	}
}

void inverse(Lnode *head)
{
	p=head->next;
	head->next=NULL;
	while(p!=NULL)
	{
		q=p->next;
		p->next=head->next;
		head->next=p;
		p=q;
	}
}

void inversePrint_Recur(Lnode *head)
{
	if(head==NULL) {
		return;
	}
	inversePrint_Recur(head->next);
	
	printf("%d ", head->data);
}

void main()
{
	Lnode *newLnode;
	newLnode=(Lnode *) malloc (sizeof(Lnode));
	create(newLnode);
	printLnode(newLnode);
	command(newLnode);
}
