#include<iostream>
using namespace std;
static const int N = 100;

int main() {
    int M[N][N];  // 0 0起点的邻接矩阵
    int n,u,k,v;

    cin >> n;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) M[i][j] = 0;
    }

    for (int i = 0;i < n;i++) {
        cin >> u >> k;
        u--;  //转换为0的起点
        for (int j = 0;j < k;j++) {
            cin >> v;
            v--;  //转换为0的起点
            M[u][v] = 1;  //在u和v之间画出一条边
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (j) cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }

    return 0;
}