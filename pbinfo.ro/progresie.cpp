#include <cstdio>
int generatedNumbers[20005];
int main() {
    freopen("progresie.in","r",stdin);
    freopen("progresie.out","w",stdout);
    int n;
    scanf("%d",&n);
    generatedNumbers[0]=1;
    for(int i=1;i<=n;++i) {
        generatedNumbers[i] = i % 2 ? 3 * generatedNumbers[(i - 1) / 2] - 1 : 3 * generatedNumbers[i / 2] - 2;
    }
    for(int i=0;i<n;++i) {
        printf("%d ",generatedNumbers[i]);
    }

    return 0;
}
