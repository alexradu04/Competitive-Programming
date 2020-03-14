#include <cstdio>
#include <cmath>

int main() {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    long long n,m;
    while (scanf("%lld %lld",&n,&m)!=EOF) {
        long double numberOfDigits=0;
        for(long long i=n-m+1;i<=n;++i) {
            numberOfDigits+=log10((double)i);
        }

        for(long long i=1;i<=m;++i) {
            numberOfDigits-= log10((double)i);
        }
        printf("%d\n",(int)numberOfDigits+1);
    }
    return 0;
}
