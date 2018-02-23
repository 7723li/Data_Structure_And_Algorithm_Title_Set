// 链式表操作集
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

void PrintList(List L){
	List temp = L;
	printf(".....");
	while(temp){
		printf("%d ", temp -> Data);
		temp = temp -> Next;
	}
	printf("\n"); return;
}

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
// PrintList(L);
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
// PrintList(L);
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);

    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");

    for ( P=L; P; P = P->Next ) 
    	printf("%d ", P->Data);

    return 0;
}

Position Find( List L, ElementType X ){
	List temp = L;
	while(temp){
		if(temp -> Data == X)
			return temp;
		temp = temp -> Next;
	}
	return ERROR;
}

List Insert( List L, ElementType X, Position P ){
	if(L == NULL){ // 链表为空, 创建并返回头结点
		List head = (List) malloc (sizeof(struct LNode));
		head -> Data = X;
		head -> Next = P;
		return head;
	}

	if(P == NULL){ // 插到链表的尾
		List temp = L;
		List rear = (List) malloc (sizeof(struct LNode));
		while(temp -> Next != NULL)
			temp = temp -> Next;
		rear -> Data = X;
		rear -> Next = NULL;
		temp -> Next = rear;
		return L;
	}

	if(L == P){ // 插到头结点前面, 即新建头结点
		List head = (List) malloc (sizeof(struct LNode));
		head -> Data = X;
		head -> Next = P;
		return head;
	}

	// 其余情况, 插到链表中间某处
	List temp, last, mid;
	temp = L; last = temp;
	while(temp != NULL){
		if(temp == P){
			mid = (List) malloc (sizeof(struct LNode));
			mid -> Data = X;
			mid -> Next = temp;
			last -> Next = mid;
			return L;
		}
		last = temp; temp = temp -> Next;
	}

	printf("Wrong Position for Insertion\n");
	return ERROR;
}

List Delete( List L, Position P ){
	// 链表空 或 删除空
	if(L == NULL || P == NULL)
		return ERROR;

	if(P == L) // 删除头结点
		return L -> Next;

	// 删除第二个至最后一个之一
	List temp = L, last = temp;
	while(temp){
		if(temp == P){
			last -> Next = temp -> Next;
			return L;
		}
		last = temp; temp = temp -> Next;
	}

	printf("Wrong Position for Deletion\n");
	return ERROR;
}

// 6
// 12 2 4 87 10 2
// 4
// 2 12 87 5
