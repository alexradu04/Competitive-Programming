#include <cstdio>
#include <unordered_map>
#include <cstring>

using namespace std;
int v[100005];
int prefixCount[(1<<20)];
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i) {
        scanf("%d",&v[i]);
    }
    int ans=0;
    int maxPrefix=2;
    for(int k=1;k<=20;++k) {
        memset(prefixCount, 0, sizeof(prefixCount));
        for(int i=1;i<=n;++i) {
            prefixCount[v[i]>>(20-k)]++;
        }
        long long matchCount=0LL;
        ans<<=1;
        for(int i=0;i<maxPrefix;++i) {
            int j=(ans^i);
            if(i==j) {
                matchCount+=1LL* prefixCount[i]* (prefixCount[i]-1)/2;
            } else if(i<j) {
                matchCount+=1LL*prefixCount[i] * prefixCount[j];
            }
        }
        if(matchCount<m) {
            ans+=1;
            m-=matchCount;
        }
        maxPrefix*=2;
    }
    printf("%d", ans);
}