#include<stdio.h>

int A[1000000],n;

//二分搜索
int binarySearch(int key){
	int left=0;
	int right=n;
	int mid;
	while(left<right){
		mid=(left+right)/2;
		if(key==A[mid]) return 1;  //发现key
		if(key>A[mid]) left=mid+1;  //搜索后半部分
		else if(key<A[mid]) right=mid;  //搜索前半部分
	}
	return 0;
}

int main(){
	int i,q,k,sum=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	scanf("%d",&k);
	for(i=0;i<q;i++){
		scanf("%d",&A[i]);
	}
	
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&k);
		if(binarySearch(k))
			sum++;
	}
	printf("%d\n",sum);
	
	return 0;
}
