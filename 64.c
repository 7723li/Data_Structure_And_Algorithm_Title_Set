#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
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

ElementType FindKth( List L, int K ){
    while(1){
        if(L == NULL)
            return ERROR;
        if(K - 1 == 0)
            return L -> Data;
        L = L -> Next;
        K--;
    }
}
