#include <cstdio>
using namespace std;
#define int long long
signed main() {
    int tc;
    scanf("%lld",&tc);
    for(int idx=1;idx<=tc;++idx) {
        int n,k;
        scanf("%lld %lld",&n,&k);
        int firstbpos=0, secondbpos;
        int st=1,dr=n;
        while(st<=dr) {
            int mid=(st+dr)/2;
            if((n-mid)*(n-mid+1)/2>=k) {
                firstbpos=mid;
                st=mid+1;
            } else
                dr=mid-1;
        }
        int cate=(n-firstbpos);
        k-=cate*(cate-1)/2;
        if(k==0) {
            secondbpos=firstbpos+1;
        } else{
            secondbpos=n-k+1;
        }
        for(int i=1;i<=n;++i) {
            printf("%c",(i==firstbpos||i==secondbpos) ? 'b' : 'a');
        }
        printf("\n");
    }
    return 0;
}
