#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode {
	int data;
	struct listNode * next;
};

typedef struct listNode LISTNODE;
typedef LISTNODE * LISTNODEPTR;

void insert(LISTNODEPTR * , int);
void delete(LISTNODEPTR * , int);
LISTNODEPTR reverseList(LISTNODEPTR , LISTNODEPTR ); 
LISTNODEPTR reverseList1(LISTNODEPTR * head);
int isEmpty(LISTNODEPTR);
void printList(LISTNODEPTR);
LISTNODEPTR findTail(LISTNODEPTR);

int main(int argc, char const *argv[])
{
	LISTNODEPTR HeadA = NULL, tailA = NULL, HeadB = NULL;

	insert(&HeadA, 10);
	insert(&HeadA, 20);
	insert(&HeadA, 30);
	printList(HeadA);

	tailA = findTail(HeadA);
	printf("%d\n", tailA->data);

	reverseList(HeadA, HeadA);
	// reverseList1(&HeadA);
	// delete(&HeadA, 30);
	// printList(HeadA);
	// delete(&HeadA, 10);
	printList(HeadA);

	return 0;
}

LISTNODEPTR findTail(LISTNODEPTR head) {
	LISTNODEPTR tail;

	for(; head->next != NULL; head = head->next)
		;
	return head;
}

void insert(LISTNODEPTR * head, int value) {
	LISTNODEPTR newPtr, previousPtr, currentPtr;

	newPtr = malloc(sizeof(LISTNODEPTR));
	if (newPtr != NULL) {
		newPtr->data = value;
		newPtr->next = NULL;

		if(*head == NULL) {
			*head = newPtr;
		} else {
			newPtr->next = *head;
			*head = newPtr;
		}
	} else {
		printf("%d not inserted. No Memory available\n", value);
	}
}

void delete(LISTNODEPTR * head, int value) {
	if(head == NULL || *head == NULL) 
		return;

	LISTNODEPTR pToBeDeleted = NULL;

	if ((*head)->data == value) {
		pToBeDeleted = *head;
		*head = (*head)->next;	
	} else {
		LISTNODEPTR tempPtr = *head;

		while (tempPtr->next != NULL && tempPtr->next->data != value)
			tempPtr = tempPtr->next;

		if (tempPtr->next != NULL && tempPtr->next->data == value) {
			pToBeDeleted = tempPtr->next;
			tempPtr->next = tempPtr->next->next;
		} 
	}  

	if (pToBeDeleted != NULL) {
		free(pToBeDeleted);
		pToBeDeleted = NULL;
	}
}

void printList(LISTNODEPTR head) {
	LISTNODEPTR ptr;

	for(ptr = head; ptr != NULL; ptr = ptr->next) {
		printf("%d-->", ptr->data);	
	}
	printf("NULL\n");
}

// 递归版本逆转链表
LISTNODEPTR reverseList(LISTNODEPTR * head, LISTNODEPTR *tail) {
	LISTNODEPTR ptr;

	if (*head == NULL) {
		return NULL;	
	} 
	if (*head == *tail) {
		return *head;
	} else {
		ptr = reverseList(&((*head)->next), &(*tail));
		ptr->next = *head;
		(*head) = ptr;
		(*tail)->next = NULL;

		return *head;
	}
}

LISTNODEPTR reverseList(LISTNODEPTR oldList, LISTNODEPTR newHead = NULL) { 
	LISTNODEPTR next = oldList->next;
	oldList->next = newHead; 
	newHead = oldList; 
	
	return (next == NULL) ? newHead : ReverseList(next,newHead); 
}

// 循环版本逆转链表
LISTNODEPTR reverseList1(LISTNODEPTR * head) {
	// LISTNODEPTR frontptr = *head, backptr = *head;
	LISTNODEPTR frontptr, backptr;
	frontptr = backptr = *head;

	if (*head == NULL) {
		return NULL;	
	}

	if (*head->next = NULL) {
		return *head;
	}

	frontptr = (*head)->next;

	while (frontptr) {
		tempptr = frontptr->next;
	
		backptr->next = frontptr->next;
		frontptr->next = *head;
		*head = frontptr;

		frontptr = tempptr;
	}
}