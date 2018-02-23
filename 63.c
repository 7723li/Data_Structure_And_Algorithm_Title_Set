// 求链式表的表长
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}

List Read(){
	int Data;
	scanf("%d", &Data);
	if(Data == -1)
		return NULL;

	List head = (List) malloc (sizeof(struct LNode));
	head -> Data = Data;
	head -> Next = NULL;
	List temp = head;

	while(1){
		scanf("%d", &Data);
		if(Data == -1)
			break;

		List mid = (List) malloc (sizeof(struct LNode));
		mid -> Data = Data;
		mid -> Next = NULL;
		temp -> Next = mid;
		temp = mid;
	}

	return head;
}

int Length( List L ){
	int len = 0;
	while(L != NULL){
		len++;
		L = L -> Next;
	}

	return len;
}
