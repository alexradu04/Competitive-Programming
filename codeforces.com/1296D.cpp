#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>neededSkips;
int main() {
    int n, a,b,k;
    scanf("%d %d %d %d",&n,&a,&b,&k);
    for(int i=1;i<=n;++i) {
        int x;
        scanf("%d",&x);
        x=x%(a+b);
        if(x==0) x=a+b;
        x=max(0,x-a);
        int noOfSkips=x/a;
        if(x%a) noOfSkips++;
        neededSkips.emplace_back(noOfSkips);
    }
    sort(neededSkips.begin(),neededSkips.end());
    int sum=0,cnt=0;
    for(int i=0;i<n;++i) {
        sum+=neededSkips[i];
        if(sum<=k) {
            cnt++;
        } else
            break;
    }
    printf("%d",cnt);
    return 0;

}
