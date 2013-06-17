#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct NodeType
{
	ElemType data;
	struct NodeType *next;
} NodeType;

typedef struct LinkQueue
{
	NodeType *front,*rear;
} LinkQueue;


NodeType *p,*s,*h;

void InitialQueue(LinkQueue *qe);
void PrintQueue(LinkQueue lq);
void Insert(LinkQueue *lq, ElemType x);
ElemType Delete(LinkQueue *lq);

void main()
{
	LinkQueue que;
	ElemType y,x;
	int i,cord;
	do {
		printf("1-Initial 2-Print 3-Insert 4-Delete 5-Quit \n");
		scanf("%d",&cord);
		switch(cord)
		{
			case 1:
				InitialQueue(&que);
				PrintQueue(que);
				break;
			case 2:
				PrintQueue(que);
				break;
			case 3:
				{
					printf("x=? ");
					scanf("%d",&x);
					Insert(&que,x);
					PrintQueue(que);
				}
				break;
			case 4:
				{
					y=Delete(&que);
					printf("Deleted x=%d .\n",y);
					PrintQueue(que);
				}
				break;
			case 5:
				exit(0);
			default:
				break;
		}
	} while(cord<=5);
}

void InitialQueue(LinkQueue *qe)
{
	p=(NodeType *) malloc (sizeof(NodeType));
	p->next=NULL;
	qe->front=p;
	qe->rear=p;
}

void PrintQueue(LinkQueue lq)
{
	printf("The queue is: ");
	p=lq.front->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf(".\n");
}

void Insert(LinkQueue *lq, ElemType x)
{
	s=(NodeType *) malloc(sizeof(NodeType));
	s->data=x;
	s->next=NULL;
	lq->rear->next=s;
	lq->rear=s;
}

ElemType Delete(LinkQueue *lq)
{
	ElemType x;
	if(lq->front==lq->rear) {
		printf("The queue is empty. \n");
		x=0;
	} else {
		p=lq->front->next;
		lq->front->next=p->next;
		if(p->next==NULL) {
			lq->rear=lq->front;
		}
		x=p->data;
		free(p);
	}
	return x;
}
