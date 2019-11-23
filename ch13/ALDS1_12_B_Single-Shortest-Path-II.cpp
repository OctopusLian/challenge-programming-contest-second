#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<pair<int,int> > adj[MAX];  //加权有向图的邻接表表示法

void dijkstra(){
    priority_queue<pair<int,int> > PQ;
    int color[MAX];
    int d[MAX];
    for (int i = 0;i < n;i++) {
        d[i] = INFTY;
        color[i] = WHITE;
    }

    d[0] = 0;
    PQ.push(make_pair(0,0));
    color[0] = GRAY;
    while(!PQ.empty()) {
        pair<int,int> f = PQ.top(); PQ.pop();
        int u = f.second;

        color[u] = BLACK;

        //取出最小值，如果不是最短路径则忽略
        if(d[u] < f.first * (-1)) continue;

        for(int j = 0;j < adj[u].size();j++) {
            int v = adj[u][j].first;
            if(color[u] == BLACK) continue;
            if(d[v] > d[u] + adj[u][j].second) {
                d[v] = d[u] + adj[u][j].second;
                //priority_queue 默认优先较大值，因此要乘以-1
                PQ.push(make_pair(d[v] * (-1),v));
                color[v] = GRAY;
            }
        }
    }

    for(int i = 0;i < n;i++) {
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }
}

int main() {
    int k,u,v,c;

    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> u >> k;
        for(int j = 0;j < k;j++) {
            cin >> v >> c;
            adj[u].push_back(make_pair(v,c));
        }
    }

    dijkstra();

    return 0;
}