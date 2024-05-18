#include <bits/stdc++.h>
using namespace std;

const int N = 505;
double dp[N][N];
bool solve() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            cin >> dp[i][j];
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dp[i][j] = max(dp[i][j], dp[i][k] * dp[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++)
        if(dp[i][i] > 1) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    cin >> q;
    while(q--) {
        cout << (solve()?"YES":"NO") << "\n";
    }
    return 0;
}