#include <bits/stdc++.h>
using namespace std;

const int di[] = {1, -1, 0, 0, 0, 0, 2, -2, 1, 1, -1, -1};
const int dj[] = {0, 0, 1, -1, 2, -2, 0, 0, 1, -1, 1, -1};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    int a[n][m]{}, d[3][n][m]{};
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];
    memset(d, 0x3f, sizeof d);

    priority_queue<tuple<int,int,int,int>> pq;
    pq.emplace(-0, 0, 0, 0);
    d[0][0][0] = 0;
    while(!pq.empty()) {
        int w,ni,nj,st;
        tie(w, ni, nj, st) = pq.top();
        w = -w; // turn weight back
        pq.pop();
        for(int i=0; i<4; i++) { // normal walk
            int ii = ni + di[i] , jj = nj + dj[i];
            if(ii > n-1 || jj > m-1 || ii < 0 || jj < 0) continue;
            if(d[st][ii][jj] <= w + a[ii][jj]) continue;
            d[st][ii][jj] = w + a[ii][jj];
            pq.emplace(-d[st][ii][jj], ii, jj, st);
        }
        if(st == 2) continue; // can't use elizabeth
        for(int i=0; i<12; i++) {
            int ii = ni + di[i] , jj = nj + dj[i];
            if(ii > n-1 || jj > m-1 || ii < 0 || jj < 0) continue;
            if(d[st+1][ii][jj] <= w) continue;
            d[st+1][ii][jj] = w;
            pq.emplace(-d[st+1][ii][jj], ii, jj, st+1);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << d[2][i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}