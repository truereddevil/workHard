#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int QElemType;

typedef struct QNode
{
	QElemType data;
	struct QNode * next;
} QNode, * QueuePtr;

typedef struct 
{
	QueuePtr front;
	QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue *Q);
Status DestroyQueue(LinkQueue *Q);
Status ClearQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q, QElemType &e);
Status EnQueue(LinkQueue *Q, QElemType e);
Status DeQueue(LinkQueue *Q, QElemType &e);
Status StackTraverse(LinkQueue S, Status (* visit)());

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

Status InitQueue(LinkQueue * Q) {
	Q->front = Q->
	rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue * Q) {
	while(Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status EnQueue(LinkQueue * Q, QElemType e) {
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data	= e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;

	return OK;
}

Status DeQueue(LinkQueue * Q, QElemType * e) {
	if (Q->front == Q->rear)	return ERROR;
	p = Q->front->next;
	e = p->data;
	Q->front->next = p->next;

	if (Q->rear == p) Q.rear = Q.front;
	free(p);
	return OK; 
}