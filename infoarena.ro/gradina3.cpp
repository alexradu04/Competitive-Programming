#include <cstdio>

using namespace std;
int partialSums[1005][1005];
bool isTree[1005][1005];
int calculateSum (int i,int j, int k) {
    return partialSums[i+k-1][j+k-1] - partialSums[i+k-1][j-1]
           - partialSums[i-1][j+k-1] + partialSums[i-1][j-1];
}
int main() {
    freopen("gradina3.in","r",stdin);
    freopen("gradina3.out","w",stdout);
    int n,p,k;
    scanf("%d %d %d",&n,&p,&k);
    for(int i=1;i<=p;++i) {
        int x,y;
        scanf("%d %d",&x,&y);
        isTree[x][y]=1;
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j)
            partialSums[i][j]=partialSums[i-1][j] +partialSums[i][j-1] - partialSums[i-1][j-1] + isTree[i][j];
    }     /*
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j)
            printf("%d ",isTree[i][j]);
        printf("\n");
    }
    printf("\n\n");
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j)
            printf("%d ",partialSums[i][j]);
        printf("\n");
    }   */
    int ans=1;
    int maxArea=-1;
    int dx,dy;
    for(int i=1;i<=n-k+1;++i) {
        for(int j=1;j<=n-k+1;++j) {
            if(calculateSum(i,j,k) > maxArea) {
                ans=1;
                maxArea=calculateSum(i,j,k) ;
            } else
            if(calculateSum(i,j,k) == maxArea) {
                ans++;
                dx=i;
                dy=j;
            }
        }
    }
    printf("%d\n%d",maxArea,ans);
    //printf("%d %d",dx,dy);
    return 0;
}
