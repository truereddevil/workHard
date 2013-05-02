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
Status HasSubTree(BiTree , BiTree);

int main(int argc, char const *argv[])
{
	BiTree father_tree = NULL, child_tree = NULL;

	CreateBitree(&father_tree);
	PreOrderTraverse(father_tree, PrintElement);
	printf("\n");	

	CreateBitree(&child_tree);
	PreOrderTraverse(child_tree, PrintElement);
	printf("\n");	

	if (HasSubTree(father_tree, child_tree))
		printf("Is sub tree!\n");
	else
		printf("Is't sub tree!\n");

	return 0;
}

Status CreateBitree(BiTree * T) {
	char ch;
	// fflush(stdin);
	setbuf(stdin, NULL);

	scanf("%c", &ch);
	if (ch == ' ') *T = NULL;
	else if (ch == '\n') {
		CreateBitree(&(*T));
	}
	else{
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

Status HasSubTree(BiTree father_tree, BiTree child_tree) {
	if (father_tree == NULL || child_tree == NULL)
		return FALSE;

	if (SycVisit(father_tree, child_tree)) {
		return OK;
	} else if (HasSubTree(father_tree->lchild, child_tree) || HasSubTree(father_tree->rchild, child_tree)) {
		return OK;
	} else {
		return FALSE;
	}
}

Status SycVisit(BiTree root1, BiTree root2) {
	if (root2 == NULL) {
		if (root1->data == root2->data) 
			if (SycVisit(root1->lchild, root2->lchild)) 
				if (SycVisit(root1->rchild, root2->rchild))
					return OK;
		return ERROR;
	} else {
		return OK;
	}	
}