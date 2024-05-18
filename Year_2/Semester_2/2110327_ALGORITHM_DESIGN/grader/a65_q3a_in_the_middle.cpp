#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+10;
vector<int> adj[N];
int d[3][N], a[3];

void bfs(int u, int i) {
    d[i][u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto& x : adj[u]) {
            if(d[i][x] != -1) continue;
            d[i][x] = d[i][u] + 1;
            q.push(x);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    cin >> a[0] >> a[1] >> a[2];
    for(int i=1, m,x; i<=n; i++) {
        for(cin >> m; m--;) {
            cin >> x;
            adj[i].push_back(x);
        }
    }
    memset(d, -1, sizeof(d));
    bfs(a[0], 0);
    bfs(a[1], 1);
    bfs(a[2], 2);
    int mn = 2e9;
    for(int i=1; i<=N; i++) {
        if(d[0][i] == -1 || d[1][i] == -1 || d[2][i] == -1) continue;
        mn = min(mn, max({d[0][i], d[1][i], d[2][i]}));
    }
    cout << mn;
    return 0;
}