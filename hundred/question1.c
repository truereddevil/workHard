#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 把二元查找树转变成排序的双向链表（）

struct BSTreeNode
{
	int m_nValue; // value of node
	BSTreeNode *m_pLeft; // left child of node
	BSTreeNode *m_pRight; // right child of node
};

struct DoubleLinkNode 
{
	int data;
	struct DoubleLinkNode *next;
	struct DoubleLinkNode *previous;
}DoubleLinkNode, * DoubleLink;

int main(int argc, char const *argv[])
{
	

	return 0;
}