#include <bits/stdc++.h>
using namespace std;
int mat[1005][1005];
int ans[1005][1005];
int n,m;
bool inBounds (int x, int y) {
    return (x>0 && x<=n) && (y>0 && y<=m);
}
ifstream in ("acces.in");
ofstream out ("acces.out");
int main() {
    freopen("acces.in","r", stdin);
    freopen("acces.out","w", stdout);
    int k;
    in >> n >> m;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            in >> mat[i][j];
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(mat[i][j] == 1) {
                ans[i][j] = min(min(ans[i][j-1], ans[i-1][j]), ans[i-1][j-1]);
                continue;
            }
            ans[i][j] = 1;
            if(mat[i-1][j]==0)
                ans[i][j] += ans[i-1][j];
            if(mat[i][j-1]==0)
                ans[i][j] += ans[i][j-1];
            if(mat[i-1][j]==0 && mat[i][j-1]==0)
                ans[i][j] -= ans[i-1][j-1];
        }
    }
    in >> k;
    for(int i=1;i<=k;++i) {
        int x,y;
        in >> x >> y;
        out << ans[x][y] << "\n";
    }
    return 0;
}
