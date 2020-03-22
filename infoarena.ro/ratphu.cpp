#include <cstdio>
#include <algorithm>
long long dp[(1<<18)][25];
int digits[20];
int rest[305];
signed main() {
    freopen("ratphu.in","r",stdin);
    freopen("ratphu.out","w",stdout);
    long long n;
    int p,numberOfDigits=0;
    fscanf(stdin,"%lld %d",&n,&p);
    while(n) {
        digits[++numberOfDigits]=n%10;
        n/=10;
    }
    std::reverse(digits + 1,digits+numberOfDigits + 1);
    for(int i=0;i<=300;++i) {
        rest[i]=i%p;
    }
    dp[0][0]=1;
    for(int i=0;i< (1<<18) ;++i) {
        for(int j=0;j<p;++j) {
            if(dp[i][j])
                for(int k=1;k<=numberOfDigits;++k) {
                    if((i&(1<<(k-1))) == 0) {
                        dp[i | (1<<(k-1))][rest[j*10+digits[k]]]+=dp[i][j];
                    }
                }
        }
    }
    fprintf(stdout,"%lld",dp[(1<<numberOfDigits)-1][0]);
    return 0;
}
