// 二叉树的遍历
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
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    // printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    // printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    // printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
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
	Tree[2] -> Right = Tree[8];

	Tree[3] -> Left = NULL;
	Tree[3] -> Right = NULL;

	Tree[4] -> Left = NULL;
	Tree[4] -> Right = NULL;

	Tree[5] -> Left = Tree[4];
	Tree[5] -> Right = NULL;

	Tree[6] -> Left = NULL;
	Tree[6] -> Right = Tree[7];

	Tree[7] -> Left = NULL;
	Tree[7] -> Right = NULL;

	Tree[8] -> Left = NULL;
	Tree[8] -> Right = NULL;

	return Tree[0];
}

void InorderTraversal( BinTree BT ){
	if(BT != NULL){
		InorderTraversal(BT -> Left);
		printf(" %c", BT -> Data);
		InorderTraversal(BT -> Right);
	}
}

void PreorderTraversal( BinTree BT ){
	if(BT != NULL){
		printf(" %c", BT -> Data);
		PreorderTraversal(BT -> Left);
		PreorderTraversal(BT -> Right);
	}
}

void PostorderTraversal( BinTree BT ){
	if(BT != NULL){
		PostorderTraversal(BT -> Left);
		PostorderTraversal(BT -> Right);
		printf(" %c", BT -> Data);
	}
}


void LevelorderTraversal( BinTree BT ){
	if(BT == NULL)
		return;

	BinTree head = BT, pop;
	BinTree Queue[1000];
	int front = 0, rear = 0, temp;
	
	Queue[rear++] = head;
	temp = rear;

	while(front != rear){
		pop = Queue[front++];
		printf(" %c", pop -> Data);
		if(pop -> Left)
			Queue[rear++] = pop -> Left;
		if(pop -> Right)
			Queue[rear++] = pop -> Right;
	}
}
