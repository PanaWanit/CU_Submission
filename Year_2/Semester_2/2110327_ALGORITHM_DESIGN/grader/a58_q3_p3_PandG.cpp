#include <bits/stdc++.h>
using namespace std;


const int N = 110;

struct A {
    int i,j,w;
    bool operator < (const A&o) const {
        return w > o.w;
    }
};
priority_queue<A> pq;

const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
char a[N][N];
int d_g[N][N], d_p[N][N];
int r,c;

void dijk(int d[N][N]) {
    while(!pq.empty()) {
        int ni = pq.top().i, nj = pq.top().j, w = pq.top().w;
        pq.pop();
        for(int i=0; i<4 ;i++) {
            int ii = ni + di[i], jj = nj + dj[i];
            if( ii > r-1 || jj > c-1 || ii < 0 || jj < 0) continue;
            if(a[ii][jj] == '#') continue;
            if(d[ii][jj] > w + 1) {
                d[ii][jj] = w + 1;
                pq.push({ii, jj, w+1});
            }
        }
    }
}
bool solve() {
    int n,t,si,sj;
    cin >> r >> c >> n >> t >> si >> sj;
    
    memset(d_g, 0x3f, sizeof d_g);
    while(n--) {
        int i,j,t;
        cin >> t >> i >> j;
        pq.push({i, j, t});
        d_g[i][j] = t;
    }

    for(int i=0; i<r; i++)
        cin >> a[i];
    dijk(d_g);
    
    memset(d_p, 0x3f, sizeof d_p);
    d_p[si][sj] = 0;
    pq.push({si, sj, 0});
    dijk(d_p);

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(d_p[i][j] <= t && d_g[i][j] > t) return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    cin >> q;
    while(q--)
        cout << (solve()?"YES":"NO") << "\n";
    return 0;
}