#include <cstdio>
#include <utility>
#include <vector>
#include <map>
#define int long long
using namespace std;
void move (char dir, int &x, int &y) {
    switch (dir) {
        case 'R': x++; break;
        case 'L': x--; break;
        case 'U': y++; break;
        case 'D': y--; break;
    }
}
vector<pair<int,int>> coordinates;
map<pair<int,int>,int> lastMet;
signed main() {
    int tc;
    scanf("%lld",&tc);
    for(int idx=1;idx<=tc;++idx) {
        int n;
        scanf("%lld\n",&n);
        int x=0,y=0;
        coordinates.clear();
        for(int i=1;i<=n;++i) {
            char ch;
            scanf("%c",&ch);
            move(ch,x,y);
            coordinates.emplace_back(make_pair(x,y));
        }
        int leftIndex=0,rightIndex=n+1,minn=1e9;
        lastMet.clear();
        lastMet[make_pair(0,0)]=1;
        for(int i=0;i<coordinates.size();++i) {
            if(i-lastMet[coordinates[i]]<rightIndex-leftIndex  &&  lastMet[coordinates[i]]!=0) {
                leftIndex=lastMet[coordinates[i]];
                rightIndex=i;
            }
            lastMet[coordinates[i]]=i+2;
        }
        if(leftIndex>0)
            printf("%lld %lld\n",leftIndex,rightIndex+1);
        else
            printf("-1\n");
    }
    return 0;
}
