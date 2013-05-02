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

typedef enum PointerTag {Link, Thread};
typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode * lchild, * rchild;
	PointerTag LTag, RTag;
} BiThrNode, * BiThrTree;

