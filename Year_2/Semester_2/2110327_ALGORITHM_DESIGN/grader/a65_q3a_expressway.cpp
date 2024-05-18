#include <bits/stdc++.h>
using namespace std;

const int N = 705;

int d[N];
struct A {
    int u,w;
    bool operator < (const A& o) const {
        return w > o.w;
    }
};
vector<pair<int,int>> adj[N];
priority_queue<A> pq;

void dijk() {
    memset(d, 0x3f, sizeof d);
    pq.push({1, 0});
    d[1] = 0;
    while(!pq.empty()) {
        int u = pq.top().u;
        pq.pop();
        for(auto& [v, w] : adj[u]) {
            if(d[v] > d[u] + w)
                d[v] = d[u] + w, pq.push({v, d[v]});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    adj[1].emplace_back(2, x);
    adj[2].emplace_back(1, x);
    for(int i=3,k; i<=n; i++) {
        cin >> k;
        while(k--) {
            int u,w;
            cin >> u >> w;
            adj[i].emplace_back(u, w);
            adj[u].emplace_back(i, w);
        }
        dijk();
        cout << d[2] << " ";
    }
    return 0;
}