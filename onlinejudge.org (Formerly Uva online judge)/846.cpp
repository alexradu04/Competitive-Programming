#include <cstdio>
using namespace std;
long long maximumNumberReached (long long steps) {
    if(steps%2) {
        return 1LL*((steps+1)/2)*((steps+1)/2);
    } else {
        return 1LL*(steps/2) * (steps/2+1);
    }
}
int main() {
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;++i) {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        long long distance=b-a;
        long long st=1,dr=distance;
        long long ans=0;
        while(st<=dr) {
            long long mid=(st+dr)/2;
            if(maximumNumberReached(mid)>=distance) {
                ans=mid;
                dr=mid-1;
            } else
                st=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
