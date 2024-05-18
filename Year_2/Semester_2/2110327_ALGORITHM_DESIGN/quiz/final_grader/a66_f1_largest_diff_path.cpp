#include<bits/stdc++.h>
using namespace std;

const int N = 2020;
int cost[N], ans = 0;
vector<int> adj[N];
int in[N], min_node[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> cost[i], min_node[i] = cost[i];
    while(m--) {
        int u,v;
        cin >> u >> v;
        in[v]++;
        adj[u].push_back(v);
    }
    queue<pair<int,int>> q; // node, min
    for(int i=0; i<n; i++) {
        if(in[i] == 0)
            q.emplace(i, cost[i]);
    }
    while(!q.empty()) {
        int u, mn;
        tie(u, mn) = q.front();
        q.pop();
        for(auto& x : adj[u]) {
            ans = max(ans, cost[x] - mn);
            min_node[x] = min(min_node[x], min_node[u]);
            if(--in[x]==0) q.emplace(x, min_node[x]);
        }
    }
    cout << ans << "\n";
    return 0;
}