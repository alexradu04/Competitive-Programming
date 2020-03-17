#include <cstdio>
long long ans[1000005];
long long diff[1000005];
int main() {
    for(long long i=4;i<=1000000;++i) {
        diff[i]=  ((i%2) ? ((i-2)/2)*(i/2) : ((i-1)/2)*((i-1)/2));
    }
    for(long long i=4;i<=1000000;++i) {
        ans[i]=ans[i-1]+diff[i];
    }
    while(1) {
        int n;
        scanf("%d",&n);
        if(n<3)
            break;
        printf("%lld\n",ans[n]);
    }
    return 0;
}
