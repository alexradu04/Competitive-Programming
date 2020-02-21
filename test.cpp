#include <cstdio>
#include <cmath>
#include <queue>
int mostFavorableSumk1[505];
int mostFavorableSumk2[505];
int effortMatrix[505][505];
int n,m,k1,k2;
using namespace std;
int solveFor2Columns (int column1, int column2) {
    if(column1==column2) return 1e9;
    if(abs(column1-column2)>=3) {
        return mostFavorableSumk1[column1] + mostFavorableSumk2[column2];
    }
    //Check later
    return 1e9;
}
int computeSoloCollumnk1(int j) {
    priority_queue<int>sortedRestingSpots;
    int sum=0;
    for(int i=1;i<=n;++i) {
        sum+=effortMatrix[i][j];
    }
    for(int i=1;i<=n;++i) {
        sortedRestingSpots.push(-1 *effortMatrix[i][j-1]);
        sortedRestingSpots.push(-1 *effortMatrix[i][j+1]);
    }
    int neededStops=k1;
    while(!sortedRestingSpots.empty() && neededStops) {
        sum+=sortedRestingSpots.top()* (-1);
        neededStops--;
    }
    return sum;
}
int computeSoloCollumnk2(int j) {
    priority_queue<int>sortedRestingSpots;
    int sum=0;
    for(int i=1;i<=n;++i) {
        sum+=effortMatrix[i][j];
    }
    for(int i=1;i<=n;++i) {
        sortedRestingSpots.push(-1 *effortMatrix[i][j-1]);
        sortedRestingSpots.push(-1 *effortMatrix[i][j+1]);
    }
    int neededStops=k2;
    while(!sortedRestingSpots.empty() && neededStops) {
        sum+=sortedRestingSpots.top()* (-1);
        neededStops--;
    }
    return sum;
}
int main() {
    freopen("lenes.in","r",stdin);
    freopen("lenes.out","w",stdout);
    int subTaskIndicaor;
    scanf("%d",&subTaskIndicaor);
    scanf("%d %d %d %d",&n,&m,&k1,&k2);
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            scanf("%d",&effortMatrix[i][j]);
        }
    }
    for(int j=1;j<=m;++j) {
        mostFavorableSumk1[j] = computeSoloCollumnk1(j);
    }
    for(int j=1;j<=m;++j) {
        mostFavorableSumk2[j] = computeSoloCollumnk2(j);
    }
    if(subTaskIndicaor==1) {
        int ans = 1e9;
        for (int column = 1; column <= m; ++column) {
            ans = min(ans, mostFavorableSumk1[column]);
        }
        printf("%d\n",ans);
        return 0;
    }
    int ans=1e9;
    for(int col1=1;col1<=m;++col1) {
        for(int col2=1;col2<=m;++col2) {
            ans=min(ans, solveFor2Columns(col1,col2));
        }
    }
    printf("%d\n",ans);
    return 0;
}
