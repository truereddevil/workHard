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

void insert(LISTNODEPTR * head, int value);
void printList(LISTNODEPTR head);
LISTNODEPTR mergeList(LISTNODEPTR , LISTNODEPTR );
ListNode * mergeList1(ListNode* pHead1, ListNode* pHead2);

int main(int argc, char const *argv[])
{
	LISTNODEPTR headA = NULL, headB = NULL, newHead = NULL;

	insert(&headA, 40);
	insert(&headA, 30);
	insert(&headA, 20);
	insert(&headA, 10);
	printList(headA);

	insert(&headB, 40);
	insert(&headB, 28);
	insert(&headB, 25);
	insert(&headB, 15);
	printList(headB);	

	newHead = mergeList1(headA, headB);
	printList(newHead);

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

// 循环版本归并
LISTNODEPTR mergeList(LISTNODEPTR headA, LISTNODEPTR headB) 
{
	LISTNODEPTR newHead = NULL, tempptr = NULL;

	if (headA == NULL) {
		return headB;
	} 

	if (headB == NULL) {
		return headA;
	}

	newHead = tempptr = headA->m_nValue <= headB->m_nValue ? headA : headB;

	if (newHead == headA)
		headA = headA->m_pNext; 
	else
		headB = headB->m_pNext;

	while (headA->m_pNext == NULL || headB->m_pNext == NULL) {
		if (headA->m_nValue <= headB->m_nValue) {
			tempptr->m_pNext = headA;
			tempptr = tempptr->m_pNext;
			headA = headA->m_pNext;
		} else {
			tempptr->m_pNext = headB;
			tempptr = tempptr->m_pNext;
			headB = headB->m_pNext;
		}
	}

	if (headA == NULL && headB != NULL) {
		for (; headB != NULL; headB = headB->m_pNext)
			tempptr->m_pNext = headB;
	}

	if (headB == NULL && headA != NULL) {
		for (; headA != NULL; headA = headA->m_pNext)
			tempptr->m_pNext = headA;
	}

	return newHead;
}

// 归并版本
ListNode * mergeList1(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	ListNode* pMergeHead = NULL;

	if (pHead1->m_nValue < pHead2->m_nValue) {
		pMergeHead = pHead1;
		pMergeHead->m_pNext = mergeList1(pHead1->m_pNext, pHead2);
	} else {
		pMergeHead = pHead2;
		pMergeHead->m_pNext = mergeList1(pHead1, pHead2->m_pNext);
	}

	return pMergeHead;
}