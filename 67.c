// 在一个数组中实现两个堆栈
#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize );
bool Push( Stack S, ElementType X, int Tag );
ElementType Pop( Stack S, int Tag );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Tag ); /* details omitted */

int main()
{
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d %d", &Tag, &X);
            if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
            break;
        case pop:
            scanf("%d", &Tag);
            X = Pop(S, Tag);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Tag);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

Stack CreateStack( int MaxSize ){
	Stack S = (Stack) malloc (sizeof(struct SNode));
	S -> Data = (ElementType*) malloc (sizeof(ElementType) * MaxSize);
	S -> Top1 = -1;
	S -> Top2 = MaxSize;
	S -> MaxSize = MaxSize;
	return S;
}

bool Push( Stack S, ElementType X, int Tag ){
	if(S -> Top2 == S -> Top1 + 1){ // 栈1满
		printf("Stack Full\n");
		return false;
	}

	if(Tag == 1)
		S -> Data[++ S -> Top1] = X;

	if(Tag == 2)
		S -> Data[-- S -> Top2] = X;

	return true;
}

ElementType Pop( Stack S, int Tag ){
	if(Tag == 1){
		if(S -> Top1 == -1){
			printf("Stack %d Empty\n", Tag);
			return ERROR;
		}
		return S -> Data[S -> Top1 --];
	}
	if(Tag == 2){
		if(S -> Top2 == S -> MaxSize){
			printf("Stack %d Empty\n", Tag);
			return ERROR;
		}
		return S -> Data[S -> Top2 ++];
	}
}

Operation GetOp(){
	char input[10];
	scanf("%s", input);
	if( strcmp(input, "Push") == 0 )return push;
	else if( strcmp(input, "Pop") == 0 ) return pop;
	else if( strcmp(input, "End") == 0 ) return end;
}

void PrintStack( Stack S, int Tag ){
	printf("Pop from Stack %d:", Tag);
	if(Tag == 1){
		while(S -> Top1)
			printf(" %d", Pop(S, 1));
		printf(" %d\n", S -> Data[S -> Top1 --]);
	}

	if(Tag == 2){
		while(S -> Top2 < S -> MaxSize)
			printf(" %d", Pop(S, 2));
		printf("\n");
	}
}

// 5
// Push 1 1
// Pop 2
// Push 2 11
// Push 1 2
// Push 2 12
// Pop 1
// Push 2 13
// Push 2 14
// Push 1 3
// Pop 2
// End