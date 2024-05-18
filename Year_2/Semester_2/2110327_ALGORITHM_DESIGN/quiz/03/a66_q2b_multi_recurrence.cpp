#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int M = 32717;

int a[N];
int dp[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    for(int i=1; i<=k; i++)
        cin >> dp[i], dp[i] %= M, cout << dp[i] << " ";
    for(int i=k+1; i<=n; i++) {
        int m;
        cin >> m;
        while(m--) {
            int x;
            cin >> x;
            dp[i] = (dp[i] + dp[max(i-x, 0)]) % M;
        }
        cout << dp[i] << " ";
    }
    return 0;
}