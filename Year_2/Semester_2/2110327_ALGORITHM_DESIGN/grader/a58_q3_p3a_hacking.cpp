#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10;
struct A {
    int u, w;
    bool operator < (const A& o) const {
        return w > o.w;
    }
};
priority_queue<A> pq;
vector<int> adj[N];
int d[N], c[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    memset(d, 0x3f, sizeof d);
    vector<int> v(k);
    for(auto& x : v) cin >> x;
    for(int i=0; i<n; i++)
        cin >> c[i];
    for(auto& x : v) {
        d[x] = c[x];
        pq.push({x, d[x]});
    }
    while(m--) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while(!pq.empty()) {
        int u = pq.top().u, W = pq.top().w;
        pq.pop();
        for(auto& x : adj[u]) {
            if(d[x] > d[u] + c[x]) {
                d[x] = d[u] + c[x];
                pq.push({x, d[x]});
            }
        }
    }
    cout << *max_element(d, d+n) << "\n";
    return 0;
}