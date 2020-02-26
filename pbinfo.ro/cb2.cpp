#include <cstdio>
#include <algorithm>
using namespace std;
int numbers[100005];
int partialSums[100005];
int partialMax[100005];
int main() {
    int n,q;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d",& numbers[i]);
        partialSums[i]=partialSums[i-1]+numbers[i];
        partialMax[i]=max(partialMax[i-1],numbers[i]);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;++i) {
        int maxNum,maxSum;
        scanf("%d %d",&maxNum,&maxSum);
        int st=1,dr=n,maxPos=0;
        while(st<=dr) {
            int mid=(st+dr)/2;
            if(partialMax[mid]>maxNum) {
                dr=mid-1;
            } else {
                maxPos=mid;
                st=mid+1;
            }
        }
        int ans=maxPos;
        maxPos=0;
        st=1,dr=n;
        while(st<=dr) {
            int mid=(st+dr)/2;
            if(partialSums[mid]>maxSum) {
                dr=mid-1;
            } else {
                maxPos=mid;
                st=mid+1;
            }
        }
        maxPos=min(ans,maxPos);
        if(maxPos==1 && (partialSums[1]>maxSum || partialMax[1]>maxNum)) {
            printf("0\n");
        } else {
            printf("%d\n", maxPos);
        }
    }
    return 0;
}
