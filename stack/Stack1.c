#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int Status;
typedef int SElemType;

typedef struct 
{
	SElemType * base;
	SElemType * top;
	int stacksize;
} SqStack;

Status InitStack(SqStack *S);
Status DestroyStack(SqStack *S);
Status ClearStack(SqStack *S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, SElemType *e);
Status Push(SqStack *S, SElemType e);
Status Pop(SqStack *S, SElemType *e);
// Status StackTraverse(SqStack S, Status (* visit)());

int main(int argc, char const *argv[])
{
	SqStack S, *sptr;
	sptr = &S;
	SElemType arr[] = {1, 2, 3, 4};

	InitStack(sptr);
	S.base = arr;

	S.top = S.base++;
	printf("%d\n", S.top);
	printf("%d\n", S.base);

	printf("%d\n", S.top-1);
	
	SElemType test, *iptr;
	printf("%d\n", test);
	iptr = &test;
	printf("%d\n", GetTop(S, iptr));
	printf("%d\n", test);

	return 0;
}

Status InitStack(SqStack *S) {
	S->base = (SElemType *) malloc(sizeof(SElemType)*STACK_INIT_SIZE);
	if (!S->base) exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S, SElemType *e) {
	if (S.top == S.base) return ERROR;
	*e = *(S.top - 1);
	printf("int GetTop, %d", *e);

	return OK;
}