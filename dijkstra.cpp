#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1000001;
int n, m, s;
vector<pair<int, int>> adj[maxn];

void input() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

const ll INF = 1e9;
int pre[maxn];

void dijkstra(int s) {
    //Mảng lưu khoảng cách đường đi
    vector<ll> d(n + 1, INF);
    vector<bool> visited(n + 1, false);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    //(khoảng cách, đỉnh)
    Q.push({0, s});
    while (!Q.empty()) {
        //Chọn ra đỉnh có khoảng cách s nhỏ nhất
        pair<int, int> top = Q.top(); Q.pop();
        int u = top.second;
        int kc = top.first;
        if (visited[u]) continue; //đỉnh đã thăm
        visited[u] = true;
        //Relaxation: cập nhật khảong cách từ s đến mọi đỉnh kề với u
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push({d[v], v});
                pre[v] = u;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
}

int main() {
    input();
    dijkstra(s);
    return 0;
}

