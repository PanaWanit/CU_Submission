#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int a[N], qs[N];
int n,m,k;
int mn;

void play(int st, int last=0, int sum=0) {
    if(st == m) {
        mn = min(mn, abs(sum - k));
        return ;
    }
    if(n-last == m - st) {
        sum += qs[n] - qs[last];
        mn = min(mn, abs(sum - k));
        return;
    }
    int i = last + 1;
    if(n-i < m - (st+1)) return;
    if(sum + a[i] - k >= mn) return;
    if(k - (qs[n]-qs[i-1]+sum) >= mn) return;
    play(st + 1, i, sum + a[i]);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for(int i=1; i<=n; i++)
        qs[i] = qs[i-1] + a[i];
    mn = qs[m];
    play(0);
    cout << mn << "\n";
    return 0;
}