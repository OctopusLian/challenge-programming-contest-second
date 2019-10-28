#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

long long cnt;
int l;
int A[1000000];
int n;
vector<int> G;

// 指定了间隔g的插入排序
void insertionSort(int A[],int n,int g) {
    for(int i = g;i < n;i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v)
        {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
        
    }
}

void shellSort(int A[],int n) {
    // 生成数列 G={1,4,13,40,121,364,1093,...}
    for (int h = 1; ; ) {
        if (h > n) break;
        G.push_back(h);
        h = 3*h + 1;
    }

    // 按逆序指定G[i] = g
    for (int i = G.size()-1;i >= 0;i--) {
        insertionSort(A,n,G[i]);
    }
}

int main() {
    cin >> n;
    // 使用速度更快的scanf函数进行输入
    for(int i = 0;i < n;i++) scanf("%d",&A[i]);
    cnt = 0;

    shellSort(A,n);

    cout << G.size() << endl;
    for(int i = G.size() - 1;i >= 0;i--) {
        printf("%d",G[i]);
        if(i) printf(" ");
    }

    printf("\n");
    printf("%d\n",cnt);
    for(int i = 0;i < n;i++) printf("%d\n",A[i]);

    return 0;
}
