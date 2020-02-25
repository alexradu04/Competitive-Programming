#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int numbers[10005];
map<int,int>frequencyMap;
int main() {
    int n;
    while(scanf("%d",&n)!=EOF) {
        int goalSum;
        for(int i=1;i<=n;++i) {
            scanf("%d",&numbers[i]);
            frequencyMap[numbers[i]]++;
        }
        sort(numbers+1,numbers+n+1);
        scanf("%d",& goalSum);
        pair<int,int>ans;
        int minn=2e9;
        for(int i=1;i<=n;++i) {
            int pos= lower_bound(numbers+1,numbers+n+1,goalSum-numbers[i])-numbers;
            if(numbers[i]+numbers[pos]==goalSum ) {
                if(numbers[i]==numbers[pos] && frequencyMap[numbers[i]]<2) continue;
                if(abs(numbers[i]-numbers[pos])<minn) {
                    ans.first = numbers[i];
                    ans.second = numbers[pos];
                    minn=abs(numbers[i]-numbers[pos]);
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",ans.first,ans.second);
    }

    return 0;
}
