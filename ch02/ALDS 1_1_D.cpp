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
		
	int maxv = -2000000000;  //����һ���㹻С�ĳ�ʼֵ
	int minv = R[0];
	
	for(int i=1;i<n;i++){
		maxv = max(maxv,R[i] - minv);  //�������ֵ
		minv = min(minv,R[i]);  //�ݴ��ֽ׶ε���Сֵ 
	} 
	cout << maxv << endl;
	return 0;
}
