#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  ListNode
{	
	int m_nValue;
	struct ListNode * m_pNext;
};

typedef struct ListNode ListNode;
typedef ListNode * LISTNODEPTR;

ListNode * FindKthToTail(ListNode *, unsigned int);
void insert(LISTNODEPTR * head, int value);
void printList(LISTNODEPTR head);

int main(int argc, char const *argv[])
{
	LISTNODEPTR HeadA = NULL, tailA = NULL, HeadB = NULL;

	insert(&HeadA, 10);
	insert(&HeadA, 20);
	insert(&HeadA, 30);
	printList(HeadA);

	LISTNODEPTR knode;
	knode = FindKthToTail(HeadA, 0);
	if (knode != NULL) 
		printf("%d\n", knode->m_nValue);
	else
		printf("Null\n");

	return 0;
}

void insert(LISTNODEPTR * head, int value) {
	LISTNODEPTR newPtr, previousPtr, currentPtr;

	newPtr = malloc(sizeof(LISTNODEPTR));
	if (newPtr != NULL) {
		newPtr->m_nValue = value;
		newPtr->m_pNext = NULL;

		if(*head == NULL) {
			*head = newPtr;
		} else {
			newPtr->m_pNext = *head;
			*head = newPtr;
		}
	} else {
		printf("%d not inserted. No Memory available\n", value);
	}
}

void printList(LISTNODEPTR head) {
	LISTNODEPTR ptr;

	for(ptr = head; ptr != NULL; ptr = ptr->m_pNext) {
		printf("%d-->", ptr->m_nValue);	
	}
	printf("NULL\n");
}

ListNode * FindKthToTail(ListNode * pListNode, unsigned int k) {
	if (pListNode == NULL || k == 0) {
		return NULL;
	}

	LISTNODEPTR frontptr = pListNode, backptr = pListNode;
	int i = 0;

	for (; i < k-1; i++) {
		if (frontptr->m_pNext) {
			frontptr = frontptr->m_pNext;
		} else {
			return NULL;
		}
	}

	while (frontptr->m_pNext != NULL) {
		frontptr = frontptr->m_pNext;
		backptr = backptr->m_pNext;	
	}

	return backptr;
}