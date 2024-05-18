#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
vector<int> adj[N];
int in[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int m;
        cin >> m;
        in[i] = m;
        while(m--) {
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
    }
    queue<int> q;
    for(int i=0; i<n; i++)
        if(in[i] == 0) q.push(i);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " " ;
        for(auto& x : adj[u]) 
            if(--in[x] == 0)
                q.push(x);
    }
    return 0;
}