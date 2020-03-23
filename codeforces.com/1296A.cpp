#include <cstdio>
using namespace std;
int v[2000];
int main() {
    int tc,n;
    scanf("%d",&tc);
    for(int idx=1;idx<=tc;++idx) {
        scanf("%d",&n);
        int nrp=0,nrip=0;
        for(int i=1;i<=n;++i) {
            scanf("%d",&v[i]);
            nrip+=v[i]%2;
            nrp+=(1-v[i]%2);
        }
        if(nrp>0 && nrip>0) printf("YES\n");
        else if(nrp==0 && nrip>0) {
            if(n%2)
                printf("YES\n");
            else
                printf("NO\n");
        } else if(nrip==0) {
            printf("NO\n");
        }
    }
    return 0;
}
