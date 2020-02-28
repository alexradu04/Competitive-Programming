#include <cstdio>
#include <algorithm>

using namespace std;
int v[10000];
long long sp[10000];
int main() {
    freopen("cb3.in","r",stdin);
    freopen("cb3.out","w",stdout);
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;++i) {
        scanf("%d",&v[i]);

    }
    sort(v+1,v+n+1);
    for(int i=1;i<=n;++i) {
        sp[i]=sp[i-1]+v[i];
    }
    for(int i=1;i<=q;++i) {
        int maxSum,ans=0;
        scanf("%d",&maxSum);
        int st=0,dr=n;
        while(st<=dr) {
            int mid=(st+dr)/2;
            if(sp[mid]>maxSum) {
                dr=mid-1;
            } else {
                st=mid+1;
                ans=mid;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
