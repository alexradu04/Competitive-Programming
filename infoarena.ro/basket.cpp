#include <cstdio>
int dp[305][305];
int main() {
    freopen("basket.in","r",stdin);
    freopen("basket.out","w",stdout);
    int tc,MOD;
    scanf("%d %d",&tc,&MOD);
    for(int i=1;i<=300;++i) {
        dp[i][0]=1;
    }
    for(int i=1;i<=300;++i) {
        for(int j=1;j<=300 && j<i;++j) {
            dp[i][j]=(1LL*dp[i-1][j]*(j+1) + 1LL* dp[i-1][j-1]*(i-j))%MOD;
        }
    }
    for(int index=1;index<=tc;++index) {
        int n,m;
        scanf("%d %d",&n,&m);
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
