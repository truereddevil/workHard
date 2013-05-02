#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10

typedef int Status;
typedef int SElemType;
typedef struct {
	SElemType data[MAXSIZE];
	int top;
} SqStack;

Status Push(SqStack *S, SElemType e);
Status Pop(SqStack *S, SElemType *e);
void PrintStack(SqStack S);

int main(int argc, char const *argv[])
{
	SElemType temp;
	SqStack test;
	test.top = -1;

	Push(&test, 10);
	Push(&test, 20);
	PrintStack(test);

	Pop(&test, &temp);
	printf("%d\n", temp);

	return 0;
}

Status Push(SqStack *S, SElemType e) 
{
	if (S->top == MAXSIZE -1) {
		return ERROR;
	}

	S->top++;
	S->data[S->top] = e;

	return OK;
}

Status Pop(SqStack *S, SElemType *e) 
{	
	if (S->top == -1) {
		return ERROR;
	}
	*e = S->data[S->top];
	S->top--;

	return OK;
}

void PrintStack(SqStack S)
{
	if (S.top == -1) {
		printf("Empty Stack!");
	} else {
		while (S.top > -1) {
			printf("%d-->", S.data[S.top]);
			S.top--;
		}
	}	
}