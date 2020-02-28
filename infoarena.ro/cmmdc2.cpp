#include <cstdio>
using namespace std;
int nums[1000005];
int frequencyNums[1000005];
int main() {
    freopen("cmmdc2.in","r",stdin);
    freopen("cmmdc2.out","w",stdout);
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;++i) {
        scanf("%d",&nums[i]);
        frequencyNums[nums[i]]++;
    }
    int ans=1;
    for(int i=2;i<=1000000;++i) {
        int cnt=0;
        for(int j=i;j<=1000000;j+=i) {
            if(frequencyNums[j]) {
                cnt+=frequencyNums[j];
            }
        }
        if(cnt>=k) {
            ans=i;
        }
    }
    int printed=0;
    printf("%d\n",ans);
    for(int i=1000000;i>=1;--i) {
        if(frequencyNums[i] && i%ans==0) {
            while(frequencyNums[i] && printed<k) {
                printf("%d ",i);
                frequencyNums[i]--;
                printed++;
            }
        }
    }
    return 0;
}
