#include <cstdio>
#define MOD 66013
long long logPut(long long a, long long b) {
    long long ret(1) ;
    for ( ; b ; b >>= 1) {
        if (b & 1) {
            ret = ret * a;
        }
        a = a * a ;
    }
    return ret ;
}
int main() {
    long long queries;
    scanf("%lld",&queries);
    for(int idx=1;idx<=queries;++idx) {
        long long a,b,m;
        scanf("%lld %lld %lld",&a,&b,&m);
        if(a==b) {
            printf("1 %lld\n",a);
            continue;
        }
        long long n=0;
        while ((a+m)*logPut(2,n)<b) {
            n++;
        }
        if((a+1)*logPut(2,n)>b) {
            printf("-1\n");
            continue;
        }
        printf("%lld ",n+2);
        printf("%lld ",a);
        for(int i=n;i>=1;--i) {
            printf("%lld ", (b/logPut(2,i-1)+1)/2);
        }
        printf("%lld\n",b);

    }
    return 0;
}