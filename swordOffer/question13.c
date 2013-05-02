#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
	int m_nValue;
	ListNode * m_pNext;
};

void DeleteNode(ListNode ** pListHead, ListNode * pToBeDeleted);

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

void DeleteNode(ListNode ** pListHead, ListNode * pToBeDeleted) 
{
	if (!pListHead || !pToBeDeleted)
		return;

	if (pToBeDeleted->next != NULL) {
		ListNode * pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		free pNext;
		pNext = NULL;
	} else if (*pListHead == pToBeDeleted) {
		free pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	} else {
		ListNode * pNode = *pListHead;

		while (pNode->m_pNext != pToBeDeleted) {
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pToBeDeleted->next;
		free pToBeDeleted;
		pToBeDeleted = NULL;
	}
}