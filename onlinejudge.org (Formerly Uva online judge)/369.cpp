#include <cstdio>
using namespace std;
int combinations[1005][1005];
void preCompute (){
    combinations[0][0]=1;
    for(int i=1;i<=1000;++i) {
        combinations[i][0]=1;
        for(int j=1;j<=i;++j) {
            combinations[i][j]= combinations[i-1][j] + combinations[i-1][j-1];
        }
    }
};
int main() {
    preCompute();
    int n=1,m=1;
    while (true) {
        scanf("%d%d",&n,&m);
        if(n==0 && m==0) {
            break;
        }
        printf("%d things taken %d at a time is %d exactly.\n",n,m,combinations[n][m]);
    }
    return 0;
}
