/*
 70 points with a map, using too musch memory
*/
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int,vector<int> >numberMap;
int main() {
    freopen("colina.in","r",stdin);
    freopen("colina.out","w",stdout);
    int n,m;;
    scanf("%d %d" ,&n,&m);
    int x;
    for(int i=1;i<=n;++i) {

        scanf("%d",&x);
        numberMap[x].emplace_back(i);
    }
    for(int i=1;i<=m;++i) {

        scanf("%d",&x);
        if(numberMap.find(x)==numberMap.end() || !numberMap[x].size())
        {
            printf("NU");
        } else
        {printf("DA ");}
        for(auto it:numberMap[x]) {
            printf("%d ",it);
        }
        printf("\n");
    }
    return 0;
}