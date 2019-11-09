#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
static const int N = 1000;

int lcs(string X,string Y) {
    int c[N + 1][N + 1];
    int m = X.size();
    int n = Y.size();
    int max1 = 0;
    X = ' ' + X;  //在X[0]中插入空格
    Y = ' ' + Y;  //在Y[0]中插入空格
    for (int i = 1;i <= m;i++) c[i][0] = 0;
    for (int j = 1;j <= n;j++) c[0][j] = 0;

    for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++) {
            if (X[i] == Y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j],c[i][j - 1]);
            }
            max1 = max(max1,c[i][j]);
        }
    }

    return max1;
}

int main() {
    string s1,s2;
    int n;cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> s1 >> s2;
        cout << lcs(s1,s2) << endl;
    }
    return 0;
}