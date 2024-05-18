#include<bits/stdc++.h>
using namespace std;

const int M = 1<<24;

int mn = 2e9;
void gogo(int x, int ans=0) {
    if(ans >= mn) return;
    int cnt = __builtin_popcount(x);
    if(cnt == 0) {
        mn = min(ans, mn);
        return;
    }
    if(cnt == 1) {
        int now = __builtin_ctz(x);
        mn = min(mn, ans + 24-now);
        return;
    }
    gogo( (x*2) % M, ans+1);
    gogo( (x+1) % M, ans+1);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int x;
    cin >> x;
    gogo(x);
    cout << mn << "\n";
    return 0;
}