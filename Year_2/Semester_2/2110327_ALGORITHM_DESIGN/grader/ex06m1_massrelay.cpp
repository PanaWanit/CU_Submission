#include <bits/stdc++.h>
using namespace std;

const int N = 5050;
int ans[N], p[N];
int fr(int i) {
    return p[i]==i?i:p[i]=fr(p[i]);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m,q;
    cin >> n >> m >> q;
    vector<tuple<int,int,int>> v(m);
    iota(p, p+n, 0);
    for(auto& [W, U, V] : v)
        cin >> U >> V >> W;
    sort(v.begin(), v.end());
    int cur = n;
    for(auto& [W, U, V] : v) {
        int ru = fr(U), rv = fr(V);
        if(ru != rv) {
            p[ru] = rv;
            ans[cur-1] = max(ans[cur], W);
            --cur;
        }
    }


    while(q--) {
        int i;
        cin >> i;
        cout << ans[i] << "\n";
    }
    return 0;
}