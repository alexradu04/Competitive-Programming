#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
int numberOfColor[100005];
int partialSumDress[100005];
int partialSumNucleus[100005];
signed main() {
    freopen("flori5.in","r",stdin);
    freopen("flori5.out","w",stdout);
    int n,k;
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;++i) {
        scanf("%lld",&numberOfColor[i]);
        partialSumDress[i]=partialSumDress[i-1]+numberOfColor[i]/k;
        partialSumNucleus[i]=partialSumNucleus[i-1]+numberOfColor[i]%k;
    }
    int m;
    scanf("%lld",&m);
    for(int i=1;i<=m;++i) {
        int leftIndex, rightIndex;
        scanf("%lld %lld",&leftIndex ,&rightIndex);
        int numberOfNucleuses=partialSumNucleus[rightIndex]-partialSumNucleus[leftIndex-1];
        int numberOfDresses=partialSumDress[rightIndex]-partialSumDress[leftIndex-1];
        if(numberOfDresses<=numberOfNucleuses) {
            printf("%lld\n", numberOfDresses);
        } else {
            int ans= ceil((numberOfDresses- numberOfNucleuses + k)/(k+1));
            printf("%lld\n", numberOfDresses-ans);
        }
    }
    return 0;
}
