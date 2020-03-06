#include <cstdio>
int R[255];
int ans[255];
int main() {
    freopen("sir42.in", "r", stdin);
    freopen("sir42.out", "w", stdout);
    int n,k;
    int pos=0,ok=0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;++i) {
        scanf("%d",&R[i]);
        if(R[i]>0)
            ans[R[i]+1]=1;
        if(R[i]==-1 && !ok)
        {pos=i-1;ok=1;}
        if(R[i]!=R[i-1] && i>1)
            ans[i-1]=1;
    }
    int cnt=0;
    for(int i=pos;i<=n;++i) {
        if(ans[i]) {
            cnt++;
        }
    }
    for(int i=pos;i<=n;++i) {
        if(ans[i]==0 && cnt<=k-1) {
            cnt++;
            ans[i]=1;
        }
    }
    for(int i=1;i<=n;++i) {
        printf("%d",ans[i]);
    }
    return 0;
}