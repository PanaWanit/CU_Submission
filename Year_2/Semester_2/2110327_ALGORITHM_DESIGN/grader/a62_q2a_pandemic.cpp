#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
int d[N][N], a[N][N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m,t;
    cin >> n >> m >> t;
    memset(d, 0x3f, sizeof(d));
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) d[i][j] = 0, q.emplace(i, j);
        }
    }
    
    while(!q.empty()) {
        int ni,nj;
        tie(ni, nj) = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int ii = ni + di[i], jj = nj + dj[i];
            if(ii > n-1 || jj > m-1 || ii < 0 || jj < 0) continue;
            if(a[ii][jj] == 2 || d[ii][jj] <= d[ni][nj] + 1) continue;
            d[ii][jj] = d[ni][nj] + 1;
            q.emplace(ii, jj);
        }
    }
    int ans=0;
    for(int i=0; i<n; i++)
        for(int j=0;j <n; j++)
            ans += (d[i][j] <= t);
    cout << ans;
    return 0;
}