#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;
int distances[50005];
int speed[50005];
int dummy,n,k;
int calculateNoOfUpgrades (int pos,long double newValue) {
    return max(0,(int)(0.5+sqrtl(1+4*distances[pos]/newValue)/2-speed[pos]));
}
int countUpgrades (long double newValue) {
    int cnt=0;
    for(int i=1;i<=n;++i) {
        cnt+=calculateNoOfUpgrades(i,newValue);
    }
    return cnt;
}
int main() {
    freopen("orase2.in","r",stdin);
    freopen("orase2.out","w",stdout);
    scanf("%d",&dummy);
    scanf("%d %d",&n,&k);
    long double maxx=0;
    for(int i=1;i<=n;++i) {
        scanf("%d",&distances[i]);
    }
    for(int i=1;i<=n;++i) {
        scanf("%d",&speed[i]);
        maxx=max(maxx, (long double)distances[i]/(speed[i]*speed[i]+1));
    }
    long double lowLimit=0,highLimit=maxx,upgradedValue;
    for(int i=1;i<=100;++i) {
        long double mid=(lowLimit+highLimit)/2;
        if(countUpgrades(mid)==k) {
            upgradedValue=mid;
            break;
        }
        if(countUpgrades(mid)>k) {
            lowLimit=mid;
        } else {
            highLimit=mid;
            upgradedValue=mid;
        }
    }
    long double ans=0;
    for(int i=1;i<=n;++i) {
        k-=calculateNoOfUpgrades(i,upgradedValue);
        speed[i]+=calculateNoOfUpgrades(i,upgradedValue);
        ans+=(long double)distances[i]/speed[i];
    }
    ans-=(long double)k*upgradedValue;
    printf("%d\n",(int)ans);
    return 0;
}
