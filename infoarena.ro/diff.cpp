#include <cstdio>
#include <algorithm>
using namespace std;
#define NORMALISE 100005
pair<int,int> solution[2000000];
int main() {
    freopen("diff.in","r",stdin);
    freopen("diff.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    int sum=0;
    int minPos=0;
    int maxPos=0;
    int minSum=1e9;
    int maxSum=-1e9;
    for(int i=1;i<=n;++i) {
        int x;
        scanf("%d",&x);
        if(x==0) {
            x--;
        }
        sum+=x;
        if(i>1) {
            solution[sum-minSum +NORMALISE] = make_pair(minPos+1,i);
            solution[sum-maxSum+NORMALISE] = make_pair(maxPos+1,i);
        }
        solution[NORMALISE+sum]=make_pair(1,i);
        if(minSum>sum) {
            minSum=sum;
            minPos=i;
        }
        if(maxSum<sum) {
            maxSum=sum;
            maxPos=i;
        }
    }
    for(int i=1;i<=m;++i) {
        int x;
        scanf("%d",&x);
        if(-n<=x && x<=n) {
            if(solution[NORMALISE+x].first==0 && solution[NORMALISE+x].second==0) {
                printf("-1\n");
            } else {
                printf("%d %d\n",solution[NORMALISE+x].first,solution[NORMALISE+x].second);
            }
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
