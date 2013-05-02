#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Tree.c: implements the datastructure of string in P127*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int TElemType;

struct BiTNode {
	TElemType data;
	struct BiTNode * lchild, * rchild;
};

typedef struct BiTNode BiTNode;
typedef BiTNode * BiTree;

Status CreateBitree(BiTree * T);
Status PreOrderTraverse(BiTree T, Status (* Visit)(TElemType e));
Status InOrderTraverse(BiTree T, Status (* Visit)(TElemType e));
Status PostOrderTraverse(BiTree T, Status (* Visit)(TElemType e));
Status LevelOrderTraverse(BiTree T, Status (* Visit)(TElemType e));
Status PrintElement(TElemType e);

int main(int argc, char const *argv[])
{
	BiTree test = NULL;

	CreateBitree(&test);
	PreOrderTraverse(test, PrintElement);

	return 0;
}

Status CreateBitree(BiTree * T) {
	char ch;

	scanf("%c", &ch);
	if (ch == ' ') *T = NULL;
	else {
		if (!(*T = (BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		(*T)->data = ch;
		
		CreateBitree(&(*T)->lchild);
		CreateBitree(&(*T)->rchild);
	}

	return OK;
}

Status PreOrderTraverse(BiTree T, Status (* Visit)(TElemType e)) {
	if (T) {
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;				
	} else {
		return OK;
	}
}

Status PrintElement(TElemType e) {
	printf("%d-->", e);

	return OK;
}