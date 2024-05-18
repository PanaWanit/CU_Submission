#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n;
vector<int> adj[N];
int in[N];

bool solve() {
    int in[N];
    memcpy(in, ::in, sizeof(in)); // bruh
    bool ans=true;
    for(int i=0, x; i<n; i++) {
        cin >> x;
        if(in[x]) ans = false;
        for(auto& a : adj[x])
            --in[a];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int m;
    cin >> n >> m;
    while(m--) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        ++in[v];
    }
    int q=5;
    while(q--) {
        cout << (solve()?"SUCCESS":"FAIL") << "\n";
    }

    return 0;
}