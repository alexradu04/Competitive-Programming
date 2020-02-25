#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
int v[200005];
int partialSums[200005];
int _calculateSum (int st, int dr) {
    return partialSums[dr]-partialSums[st-1];
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d",&v[i]);
        partialSums[i]=partialSums[i-1]+v[i];
    }
    // printf("%d %d %d\n",_calculateSum(9,19),_calculateSum(9,20),_calculateSum(9,21));
    // printf("%d %d %d\n",_calculateSum(19,n),_calculateSum(20,n),_calculateSum(21,n));
    int soli=-1,solj=-1;
    int ans= (1<<30);
    for(int i=1;i<n;++i) {
        int st=i+1,dr=n;
        int sum=_calculateSum(1,i);
        int ansmin=i+1,ansmax=n;
        while(st<=dr) {
            int mid= st + (dr-st)/2;
            if(_calculateSum(i+1,mid) < sum) {
                st=mid+1;
                ansmin=mid;
            } else if(_calculateSum(i+1,mid) > sum) {
                ansmax = mid;
                dr = mid - 1;
            }
            else
            {
                ansmax=ansmin=mid;
                break;
            }
        }
        //printf("%d %d %d\n",i,ansmin,ansmax);
        ansmax--;
        ansmax--;
        for(int j=-2;j<=2 && ansmax<n; j++,ansmax++) {
            if (max(sum, max(_calculateSum(i + 1, ansmax), _calculateSum(ansmax + 1, n))) -
                min(sum, min(_calculateSum(i + 1, ansmax), _calculateSum(ansmax + 1, n))) < ans) {
                ans = max(sum, max(_calculateSum(i + 1, ansmax), _calculateSum(ansmax + 1, n))) -
                      min(sum, min(_calculateSum(i + 1, ansmax), _calculateSum(ansmax + 1, n)));
                soli = i;
                solj = ansmax;
            }
        }
    }
    printf("%d %d",soli,solj);
    return 0;
}
