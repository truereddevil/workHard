#include <iostream>
#include <stdlib.h>
#include "assert.h" 

using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;      
};
 
void InitList(ListNode** head)
{
    *head = (ListNode*)malloc(sizeof(ListNode));
    (*head)->m_pNext = NULL;    
}
 
void InsertList(ListNode* head, int data)
{
   assert(head != NULL);
   ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
   pNewNode->m_nKey = data;
   pNewNode->m_pNext = head->m_pNext;
   head->m_pNext = pNewNode;     
}
 
void PrintList(ListNode* pHead)
{
   if(pHead == NULL)    
   {
       return;        
   }
  
   ListNode* pTempNode = pHead->m_pNext;
   while(pTempNode != NULL)
   {
       std::cout<<pTempNode->m_nKey<<std::endl;
       pTempNode = pTempNode->m_pNext;                    
   }
}
 
//反转链表核心算法
ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pReverseHead = NULL;
    ListNode* pNode = pHead->m_pNext;
    ListNode* pPrev = NULL;
   
    while(pNode != NULL)
    {
        //存储当前节点pNode的下一个节点
        ListNode* pNext = pNode->m_pNext;
       
        //如果下一个节点为空，那么当前节点pNode就是反转后的头指针了
        if(pNext == NULL)
        {
            pReverseHead = pNode;        
        }
       
        //将当前节点改为指向pPrev节点
        pNode->m_pNext = pPrev;
       
        //移动两个指针
        pPrev = pNode;
        pNode = pNext;
    }
    //添加头指针
    ListNode* pReturn = (ListNode*)malloc(sizeof(ListNode));
    pReturn->m_pNext = pReverseHead;
    return pReturn;
}
 
ListNode* ReverseLink(ListNode* pHead)
{
    if(pHead->m_pNext == NULL)
        return pHead;
    ListNode* pReturn = ReverseLink(pHead->m_pNext);
    pHead->m_pNext->m_pNext = pHead;
    pHead->m_pNext = NULL;
    return pReturn;
}
 
//反转链表的递归算法
ListNode* ReverseList2(ListNode* pHead)
{
    ListNode* pReverseHead = pHead;
    //考虑只有0个或1个节点
    if(pHead->m_pNext == NULL || pHead->m_pNext->m_pNext == NULL)
    {
        return pHead;                 
    }         
    pReverseHead->m_pNext = ReverseLink(pReverseHead->m_pNext);
    return pReverseHead;
}
 
 
int main()
{
    ListNode* pListHead = NULL;
    InitList(&pListHead);
   
    //建立两个链表
    for(int i=9; i>=0; i--)
    {
        InsertList(pListHead, i);       
    }
   
    std::cout<<"链表反转之前："<<std::endl;
    PrintList(pListHead);
   
    //ListNode* pReverseHead = ReverseList(pListHead);
    ListNode* pReverseHead = ReverseList2(pListHead);
   
    std::cout<<"链表反转之后："<<std::endl;
    PrintList(pReverseHead);
    system("pause");
    return 0;
}