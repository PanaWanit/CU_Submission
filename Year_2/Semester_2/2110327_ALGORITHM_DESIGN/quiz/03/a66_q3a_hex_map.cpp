#include<bits/stdc++.h>
using namespace std;

const int N = 303;
int a[N][N];
int d[N][N];
struct A {
    int i,j,w;
    bool operator < (const A& o) const {
        return w > o.w;
    }
};
const int di[2][6] = {{-1, -1, 1, 1, 0, 0}, {-1, -1, 1, 1, 0, 0}};
const int dj[2][6] = {{-1, 0, -1, 0, -1, 1}, {0, 1, 0, 1, -1, 1}};
priority_queue<A> pq;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m,si,sj,ei,ej;
    cin >> n >> m;
    cin >> sj >> si >> ej >> ei;
    for(int i=0; i<n;i ++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    --si, --sj, --ei, --ej;
    memset(d, 0x3f, sizeof d);
    d[si][sj] = a[si][sj];
    pq.push({si, sj, a[si][sj]});
    while(!pq.empty()) {
        int ni = pq.top().i, nj = pq.top().j;
        pq.pop();
        for(int i=0; i<6; i++) {
            int ii = ni + dj[nj%2][i], jj = nj + di[nj%2][i];
            if(ii > n-1 || jj > m-1 || ii < 0 || jj < 0) continue;
            if(d[ii][jj] > d[ni][nj] + a[ii][jj]) {
                d[ii][jj] = d[ni][nj] + a[ii][jj];
                pq.push({ii, jj, d[ii][jj]});
            }
        }
    }
    cout << d[ei][ej] << "\n";
    return 0;
}