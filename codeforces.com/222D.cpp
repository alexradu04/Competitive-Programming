#include <bits/stdc++.h>

using namespace std;
int a[200005];
int b[200005];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;++i) {
        scanf("%d",&b[i]);
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int cnt=0,j=n;
    for(int i=1;i<=n;++i) {
        if(a[i]+ b[j]>=k) {
            cnt++;
            j--;
        }
    }
    printf("1 %d",cnt);
    return 0;
}
