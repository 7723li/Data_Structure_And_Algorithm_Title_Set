// 八皇后问题枚举法解析_1
// 八皇后问题回溯法解析_2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QueenNums 8

int sum;

void showQueens(int* queenArr){
	int i, j ;
	for(i = 0; i < QueenNums; i++){
		// 打印皇后前面的空余部分
		for(j = 0; j < queenArr[i]; j++)
			printf("%c ", 1);
		if(queenArr[i] > -1)
			printf("%c ", 2);
		else
			printf("%c ", 1);
		// 打印皇后前面的空余部分
		for(j+1; j < QueenNums; j++)
			printf("%c ", 1);
		printf("\n");
	}
}

/***** 枚举法,枚举每种可能性 10皇后603秒*****/
bool isClashEnum(int* queenArr){ // 冲突
	int i, j;
	for(i = 1; i <= QueenNums; i++){
		for(j = 0; j < i; j++){
			if(queenArr[i] == queenArr[j]) // 在同一列
				return true;
			if(abs(queenArr[i] - queenArr[j]) == abs(i - j)) // 对角线
				return true;
		}
	}
	return false;
}

void enumQueenPosition(int* queenArr){
	for(queenArr[0] = 0; queenArr[0] < QueenNums; queenArr[0]++)
		for(queenArr[1] = 0; queenArr[1] < QueenNums; queenArr[1]++)
			for(queenArr[2] = 0; queenArr[2] < QueenNums; queenArr[2]++)
				for(queenArr[3] = 0; queenArr[3] < QueenNums; queenArr[3]++)
					for(queenArr[4] = 0; queenArr[4] < QueenNums; queenArr[4]++)
						for(queenArr[5] = 0; queenArr[5] < QueenNums; queenArr[5]++)
							for(queenArr[6] = 0; queenArr[6] < QueenNums; queenArr[6]++)
								for(queenArr[7] = 0; queenArr[7] < QueenNums; queenArr[7]++){
									if(isClashEnum(queenArr))
										continue;
									else{
										sum++;
										showQueens(queenArr);
										printf("\n");
									}
								}
}

/***** 回溯法 10皇后18秒*****/
bool isClash(int* queenArr, int nRow){
	int i;
	for(i=0; i<nRow; i++){
		if(queenArr[i] == queenArr[nRow])
			return true;
		if(abs(queenArr[i] - queenArr[nRow]) == abs(i - nRow))
			return true;
	}
	return false;
}

void DFS(int* queenArr,int nRow){
	int i;
	for(i = 0; i < QueenNums; i++){
		queenArr[nRow] = i; // 把皇后放在当前行的循环位置
		// 若位置冲突，则忽略下面所有的摆放问题
		if(!isClash(queenArr, nRow)){
			if(nRow == QueenNums - 1){
				// 全部完成
				sum++;
				showQueens(queenArr);
				printf("\n");
			}
			else
				DFS(queenArr,nRow + 1);
		}
		else continue;
	}
}

int main(int argc, char const *argv[])
{
	// 每个组织成员代表一个皇后的位置
	// 比如 queenArr[0] = 4 代表第一行的皇后在第五格
	int queenArr[QueenNums];
	double start, end;
	memset(queenArr,-1,sizeof(queenArr));

	// sum = 0;
	// start = clock();
	// enumQueenPosition(queenArr);
	// end = clock();
	// printf("%d %.3lf\n", sum, (end - start) / CLK_TCK);

	sum = 0;
	start = clock();
	DFS(queenArr, 0);
	end = clock();
	printf("%d %.3lf\n", sum, (end - start) / CLK_TCK);

	return 0;
}
