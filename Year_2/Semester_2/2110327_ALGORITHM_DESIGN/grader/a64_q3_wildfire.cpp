#include <bits/stdc++.h>
using namespace std;

const int N = 5050;
int ans=0;
int c[N];
bool vis[N];
vector<int> adj[N];
void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    ans -= c[u];
    for(auto& x : adj[u]) {
        dfs(x);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        cin >> c[i], ans += c[i];
    vector<int> v(k);
    for(auto& x : v)
        cin >> x;
    while(m--) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(auto& x : v)
        dfs(x), cout << ans << " ";
    return 0;
}