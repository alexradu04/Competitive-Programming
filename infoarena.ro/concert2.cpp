#include <cstdio>
#include <vector>
using namespace std;
int beatFrequencies[2505];
int longestSeqEndingIn[2505];
int lengthOfAscendingSeq[2505];
int lenghtOfDescending[2505];
int main() {
    freopen("concert2.in","r",stdin);
    freopen("concert2.out","w",stdout);
    int n,k1,k2;
    scanf("%d %d %d",&n,&k1,&k2);
    for(auto i=1;i<=n;++i) {
        scanf("%d",&beatFrequencies[i]);
    }
    for(auto i=1;i<=n;++i) {
        longestSeqEndingIn[i]= lengthOfAscendingSeq[i]= lenghtOfDescending[i]=1;
        for(auto j=1;j<i;++j) {
            if(beatFrequencies[j]<beatFrequencies[i]) {
                if(lengthOfAscendingSeq[j] < k1) {
                    if(longestSeqEndingIn[i]<longestSeqEndingIn[j]+1) {
                        longestSeqEndingIn[i]=longestSeqEndingIn[j]+1;
                        lengthOfAscendingSeq[i]= lengthOfAscendingSeq[j] + 1;
                        lenghtOfDescending[i]=1;
                    }
                }
            } else if(beatFrequencies[j]>beatFrequencies[i]) {
                if(lenghtOfDescending[j]<k2) {
                    if(longestSeqEndingIn[i]<longestSeqEndingIn[j]+1) {
                        longestSeqEndingIn[i]=longestSeqEndingIn[j]+1;
                        lenghtOfDescending[i]=lenghtOfDescending[j]+1;
                        lengthOfAscendingSeq[i]=1;
                    }
                }
            }
        }
    }
    int ans=-1e9;
    for(auto i=1;i<=n;++i) {
        ans=max(ans,longestSeqEndingIn[i]);
    }
    printf("%d",ans);
    return 0;
}
