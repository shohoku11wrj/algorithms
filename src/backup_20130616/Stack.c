#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100;
typedef int ElemType;
typedef struct 
{
	ElemType elem[100];
	int top;
} SqStack;

void main()
{
	void InitStack(SqStack *S);
	void Push(SqStack *p, ElemType x);
	ElemType Pop(SqStack *p);
	void Clear(SqStack *p);
	void Command(SqStack *p);
	
	SqStack *ss;
	ss=(SqStack *) malloc(sizeof(SqStack));
	InitStack(ss);
	Command(ss);
}

void InitStack(SqStack *S)
{
	S->top=-1;
}

void Push(SqStack *S, ElemType x)
{
	if(S->top<100-1)
	{
		S->top++;
		S->elem[(S->top)]=x;
	}
	else {
		printf("Stack Overflow!\n");
	}
}

ElemType Pop(SqStack *S)
{
	ElemType x;
	if(S->top==-1)
	{
		printf("Underflow!\n");
		return -1;
	}
	else {
		x=S->elem[S->top];
		S->top--;
		return x;
	}
}

void Print(SqStack p)
{
	printf("Stack is: ");
	if(p.top==-1) {
		printf("NULL .");
	} else {
		for(int i=0;i<=p.top;i++)
		{
			printf("%d ",p.elem[i]);
		}
	}
	printf("\n");
}

void Clear(SqStack *p)
{
	p->top=-1;
}

void Command(SqStack *p)
{
	printf("1- Print 2-Push 3-Pop 4-Clear 5-Quit\n");
	int cmd;
	scanf("%d",&cmd);
	switch(cmd)
	{
		case 1: 
			Print(*p);
			break;
		case 2:
		{
			ElemType push;
			printf("Input push number: ");
			scanf("%d",&push);
			Push(p,push);
			break;
		}
		case 3:
		{
			ElemType res;
			res=Pop(p);
			printf("Poped number: %d .\n",res);
			break;
		}
		case 4: 
			Clear(p);
			break;
		case 5: break;
		default: break;
	}
	if(cmd!=5) {
		Command(p);
	}
}
