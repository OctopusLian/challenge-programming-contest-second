#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 200000;

int main()
{
	int R[MAX],n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> R[i];
		
	int maxv = -2000000000;  //设置一个足够小的初始值
	int minv = R[0];
	
	for(int i=1;i<n;i++){  //如果每次都在每一阶段直接读取R[j]，那么数组可以省去更新最大值
		maxv = max(maxv,R[i] - minv);  
		minv = min(minv,R[i]);  //暂存现阶段的最小值
	} 
	cout << maxv << endl;
	return 0;
}
