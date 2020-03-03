#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
map<pair<int,int>, int>vis;
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    int ok=0;
    for(int i=1;i<=q;++i) {
        int x,y;
        scanf("%d %d",&x,&y);
        int multiplier=(vis[make_pair(x,y)]? -1 : 1);
        ok+=multiplier*(vis[make_pair(3-x,y-1)] + vis[make_pair(3-x,y)] + vis[make_pair(3-x,y+1)]);
        vis[make_pair(x,y)]=!vis[make_pair(x,y)];
        if(ok) {
            printf("No\n");
        } else
            printf("Yes\n");
    }
    return 0;
}
