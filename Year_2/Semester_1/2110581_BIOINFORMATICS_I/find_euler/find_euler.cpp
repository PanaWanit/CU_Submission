#include <bits/stdc++.h>
using namespace std;

const int N = 3010;

bool adj[N][N];
int deg[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		deg[u]++, deg[v]++;
	}
	int u = -1, v = -1;
	for(int i = 0; i < n; i++) {
		if(deg[i] & 1) {
			if(u == -1)
				u = i;
			else if(v == -1)
				v = i;
			else {
				cout << "BAD";
				return 0;
			}
		}
	}
	stack<int> st;
	st.push(v);	 // swap u to v if output is -1
	vector<int> ans;
	while(!st.empty()) {
		int now = st.top();
		int i;
		for(i = 0; i < n; i++)
			if(adj[now][i]) break;

		if(i == n) {
			ans.push_back(now);
			st.pop();
		}
		else {
			adj[now][i] = 0;
			st.push(i);
		}
	}
	if((int)ans.size() != m + 1) {
		cout << -1 << "\n";
		return 0;
	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < (int)ans.size(); i++) {
		if(i + 1 != (int)ans.size())
			cout << ans[i] << "->";
		else
			cout << ans[i];
	}
	cout << "\n";
	return 0;
}