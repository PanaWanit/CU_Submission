#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int cnt=0, ans = 0, k;
bool vis[N];
vector<int> adj[N];
void dfs(int u, int l=0) {
    if(l > k) return;
    cnt += 1-vis[u];
    vis[u] = 1;
    for(auto& x : adj[u])
        dfs(x, l+1);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin >> n >> m >> k;
    while(m--) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<n; i++) {
        cnt = 0;
        dfs(i);
        memset(vis, 0, sizeof vis);
        ans = max(cnt, ans);
    }
    cout << ans << "\n";
    return 0;
}