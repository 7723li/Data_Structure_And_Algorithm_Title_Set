#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}

BinTree CreatBinTree(){
	int i;
	BinTree Tree[10];
	for(i=0; i<9; i++){
		Tree[i] = (BinTree) malloc (sizeof(struct TNode));
		Tree[i] -> Data = 'A' + i;
	}
	Tree[0] -> Left = Tree[1];
	Tree[0] -> Right = Tree[2];

	Tree[1] -> Left = Tree[3];
	Tree[1] -> Right = Tree[5];

	Tree[2] -> Left = Tree[6];
	Tree[2] -> Right = Tree[9];

	Tree[4] -> Left = Tree[3];
	Tree[6] -> Right = Tree[8];

	return Tree[0];
}

int max(int a, int b){
	return a > b ? a : b;
}

int GetHeight( BinTree BT ){
	if(BT == NULL)
		return 0;

	return 1 + max(GetHeight(BT -> Left), GetHeight(BT -> Right));
}