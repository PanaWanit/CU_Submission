#include<bits/stdc++.h>
using namespace std;

const int N = 750;

int a[2][N][N];
int d[2][N][N];
int sz[N];
const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};
queue<tuple<int,int,int>> q;
int n,m, n_comp=0;

void dfs(int si, int sj, int st) {
    if(a[st][si][sj] == 1) return;
    q.emplace(si, sj, st);
    d[st][si][sj] = n_comp;
    int cnt=0;
    while(!q.empty()) {
        int x, ni, nj;
        tie(ni, nj, x) = q.front();
        q.pop();
        cnt++;
        for(int i=0; i<4; i++) {
            int ii = ni + di[i], jj = nj + dj[i];
            if(ii > n || jj > m || ii < 1 || jj < 1) continue;
            if(a[x][ii][jj] == 1 || d[x][ii][jj] != -1) continue;
            d[x][ii][jj] = n_comp;
            q.emplace(ii, jj, x);
        }
    }
    sz[n_comp++] = cnt;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int k;
    cin >> n >> m >> k;
    for(int k=0; k<2; k++) {
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++)
                cin >> a[k][i][j];
        }
    }
    memset(d, -1, sizeof d);
    dfs(1, 1, 0);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(d[0][i][j] != -1 && d[1][i][j] == -1 && a[1][i][j] == 0) {
                dfs(i, j, 1);
            }
        }
    }
    int mx = 0;
    while(k--) {
        int x,y;
        cin >> x >> y;
        if(d[0][x][y] != -1) 
            mx = max(mx, sz[ d[1][x][y] ]);
    }

    cout << sz[0] + mx;
    return 0;
}