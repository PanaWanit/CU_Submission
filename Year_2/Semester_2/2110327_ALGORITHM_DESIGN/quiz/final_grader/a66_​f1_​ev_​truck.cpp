#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int n;
int dp[N][N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int m;
    cin >> n >> m;
    memset(dp, 0x3f, sizeof(dp));
    for(int i=0; i<n; i++)
        dp[i][i] = 0;
    while(m--){ 
        int u,v,w;
        cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = min(dp[u][v], w);
    }
    for(int k=0; k<n; k++ ){
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++ ){ 
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    int mx=0;
    for(int i=0; i<n; i++ ){
        for(int j=0; j<n; j++ ) {
            mx = max(dp[i][j], mx);
        }
    }
    cout << mx << "\n";
    return 0;
}