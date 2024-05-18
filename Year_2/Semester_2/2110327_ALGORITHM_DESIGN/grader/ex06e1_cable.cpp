#include <bits/stdc++.h>
using namespace std;

vector<int> p;
int fr(int i) {
    return p[i] == i ? i : p[i]=fr(p[i]);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<tuple<int,int,int>> w;
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    for(int i=0; i<n-1; i++) {
        for(int j=i+1, x; j<n; j++) {
            cin >> x;
            w.emplace_back(x, i, j);
        }
    }
    sort(w.begin(), w.end());
    int ans=0;
    for(auto& [cost, u, v] : w) {
        int ru = fr(u), rv = fr(v);
        if(ru != rv) {
            p[ru] = rv;
            ans += cost;
        }
    }
    cout << ans << "\n";
    return 0;
}