#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
int rayLength[1005];
map<double,int>coTangentFrequency;
int registerTargets(int x) {
    int cnt=0;
    int sumOfSquares=x*x;
    for(int cathetus1=1;cathetus1<x;++cathetus1) {
        int cathetus2Squared=sumOfSquares - cathetus1*cathetus1;
        int cathetus2=(int)sqrt((double)cathetus2Squared);
        if(cathetus2*cathetus2 == cathetus2Squared) {
            cnt++;
            double key= (floor((1.0*cathetus1/cathetus2)*1000000.0)) / 1000000.0;
            coTangentFrequency[key]++;
        }
    }
    return cnt;
}
int main() {
    freopen("poligon6.in","r",stdin);
    freopen("poligon6.out","w",stdout);
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d",&rayLength[i]);
        sum+=registerTargets(rayLength[i]);
    }
    printf("%d\n",sum);
    int ans=0;
    vector<int>freqs;
    for(auto it:coTangentFrequency) {
        if(it.second>0){
            ans++;
            freqs.emplace_back(it.second);
        }
    }
    printf("%d\n",ans);
    for(auto it:freqs) {
        printf("%d ",it);
    }
    return 0;
}
