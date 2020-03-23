#include <cstdio>

int main() {
    int tc;
    scanf("%d",&tc);
    for(int i=1;i<=tc;++i) {
        int n;
        scanf("%d",&n);
        int totalSpent=0;
        while(n>=10) {
            int cashBack= n/10;
            totalSpent+=(cashBack)*10;
            n-= (cashBack)*10;
            n+=cashBack;
        }
        totalSpent+=n;
        printf("%d\n",totalSpent);
    }
    return 0;
}
