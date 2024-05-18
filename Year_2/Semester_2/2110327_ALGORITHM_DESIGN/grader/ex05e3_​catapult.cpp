#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
vector<int> adj[N];

int low[N], idx[N], onstack[N], scc[N];
int id=0, comp = 0;
multiset<int> sz;
stack<int> st;
void tarjan(int u) {
    idx[u] = low[u] = ++id;
    st.push(u);
    onstack[u] = 1;
    for(auto& x : adj[u]) {
        if(!idx[x]) {
            tarjan(x);
            low[u] = min(low[u], low[x]);
        }
        else if(onstack[x]) {
            low[u] = min(low[u], idx[x]);
        }
    }
    if(idx[u] == low[u]) {
        ++comp;
        int cur_size = 0;
        while(!st.empty() && st.top() != u) {
            int v = st.top();
            st.pop();
            scc[v] = comp;
            onstack[v] = 0;
            cur_size ++;
        }

        st.pop();
        scc[u] = comp;
        onstack[u] = 0;
        ++cur_size;

        sz.insert(cur_size);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int m;
        cin >> m;
        while(m--) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    for(int i=0; i<n; i++)
        if(!idx[i]) tarjan(i);

    for(auto& x : sz)
        cout << x << " ";
    cout << "\n";
    return 0;
}