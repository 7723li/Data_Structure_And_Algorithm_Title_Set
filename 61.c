// 单链表逆转
#include <stdio.h>
#include <stdlib.h>

int size;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read(); 
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Read(){
	int i, Data;
	scanf("%d", &size);

	if(size <= 0) return NULL;

	scanf("%d", &Data);
	List head = (List) malloc (sizeof(struct Node));
	head -> Data = Data;
	head -> Next = NULL;
	List temp = head;
	for(i=1; i<size; i++){
		scanf("%d", &Data);
		List mid = (List) malloc (sizeof(struct Node));
		mid -> Data = Data;
		mid -> Next = NULL;
		temp -> Next = mid;
		temp = mid;
	}
	return head;
}

List Reverse( List L ){
	List front, rear, tag;
	front = L;
	if(!front) return NULL;
	rear = front->Next;
	front->Next = NULL;
	while(rear){
		tag = rear->Next;
		rear->Next = front;
		front = rear;
		rear = tag;
	}
	L = front;
	return L;
}

void Print( List L ){
	while(L != NULL){
		printf("%d ", L -> Data);
		L = L -> Next;
	}
	printf("\n");
}

// 1 2 3 4 5 6 7 8 9 10
