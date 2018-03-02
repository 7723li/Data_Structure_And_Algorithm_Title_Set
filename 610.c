// 二分查找
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput(){
    int len, i;
    List l = (List) malloc (sizeof(struct LNode));

    scanf("%d", &len);
    for(i=0; i<len; i++)
        scanf("%d", &(l -> Data[i]));
    l -> Last = len - 1;

    return l;
}

Position BinarySearch( List L, ElementType X ){
    if(L){
        Position low = 1, high = L -> Last, mid;

        while(low <= high){
            mid = (high + low) / 2;
            if(X == L -> Data[mid])
                return mid;
            if(X < L -> Data[mid])
                high = mid - 1;
            if(X > L -> Data[mid])
                low = mid + 1;
        }

        return NotFound;
    }
    return NotFound;
}

// 输入样例1：
// 5
// 12 31 55 89 101
// 31
// 输出样例1：
// 2
// 输入样例2：
// 3
// 26 78 233
// 31
// 输出样例2：
// 0
