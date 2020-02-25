#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int constraints[100005];
vector<pair<int,int>>adj[100005];
map<int,bool>visited;
queue<int>bfsQueue;
int main() {
    freopen("timeline.out","r",stdin);
    freopen("timeline.in","w",stdout);
    int n,m,c;
    scanf("%d %d %d",&n,&m,&c)  ;
    for(int i=1;i<=n;++i) {
        scanf("%d",&constraints[i]);
    }
    for(int i=1;i<=c;++i) {
        int u,v,cost;
        scanf("%d %d %d",&u,&v,&cost);
        adj[u].emplace_back(make_pair(v,cost));
        visited[v]=1;
    }
    for(int i=1;i<=n;++i) {
        if(visited.find(i)==visited.end()) {
            bfsQueue.push(i);
        }
    }
    while(!bfsQueue.empty()) {
        int currentNode=bfsQueue.front();
        bfsQueue.pop();
        for(auto it: adj[currentNode]) {
            if(constraints[it.first]<constraints[currentNode]+ it.second) {
                constraints[it.first]= constraints[currentNode]+ it.second;
                bfsQueue.push(it.first);
            }
        }
    }
    for(int i=1;i<=n;++i) {
        printf("%d\n",constraints[i]);
    }
    return 0;
}
