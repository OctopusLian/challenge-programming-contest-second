/*
	
Insertion Sort

*/

#include<stdio.h>
void trace(int A[],int N){  //按顺序输出数组元素
	int i;
	for(i=0;i<N;i++){
		if(i>0) printf(" ");  //在相邻元素之间输出1个空格
		printf("%d",A[i]);
	}
	printf("\n");
}

void insertionSort(int A[],int N){  //插入排序(0起点数组)
	int j,i,v;
	for(i=1;i<N;i++){
		v=A[i];
		j=i-1;
		while(j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		trace(A,N);
	}
}

int main()
{
	int N,i,j;
	int A[100];
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",&A[i]);
	trace(A,N);
	insertionSort(A,N);
	return 0;
}
