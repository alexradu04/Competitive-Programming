#include <cstdio>
#include <algorithm>
#define int long long
int nums[105][25000];
int linearSums[105];
using namespace std;

signed main() {
    freopen("livada3.in","r",stdin);
    freopen("livada3.out","w",stdout);
    int n,m,c,r,x,y,z,w,u;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",&n,&m,&c,&r,&x,&y,&z,&w,&u);
    for(int i=1;i<=m;++i) {
        scanf("%lld ",&nums[1][i]);
    }
    for(int i=2;i<=n;++i) {
        scanf("%lld",&nums[i][1]);
        for (int j = 2; j <= m; ++j)
            nums[i][j] = (x * nums[i - 1][j] + y * nums[i][j - 1] + z * nums[i - 1][j - 1] + w) % u;
    }
    int st=1,dr=1e9,ans=0;
    while(st<=dr) {
        int mid=(1LL*st+dr)/2;
        for(int i=1;i<=n;++i) {
            linearSums[i]=0;
            for(int j=1; j<=m&&nums[i][j]<=mid;++j) {
                linearSums[i]+=nums[i][j];
            }
        }
        sort(linearSums+1,linearSums+n+1);
        long long sum=0;
        for(int i=n;i>=n-r+1;--i) {
            sum+=linearSums[i];
        }
        if(sum>=c) {
            ans=mid;
            dr=mid-1;
        }
        if(sum<c) {
            st=mid+1;

        }
    }
    printf("%lld",ans);
    return 0;
}
