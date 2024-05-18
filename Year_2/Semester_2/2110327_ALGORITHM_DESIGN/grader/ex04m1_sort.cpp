#include <bits/stdc++.h>
using namespace std;

int a[100000], c[4], c2[4];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i], ++c[a[i]];
    int cnt=0, cur=1;
    for(int i=0; i<n && cur<3; i++) {
        if(a[i] > cur) cnt++, c2[a[i]]++;
        if(a[i] < cur) {
            if(c2[2]) --c2[2];
            else cnt++;
        }
        if(!--c[cur]) cur++;
    }

    cout << cnt << "\n";
    return 0;
}