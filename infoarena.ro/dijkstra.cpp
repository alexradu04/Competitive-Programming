#include <fstream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;
ifstream in ("dijkstra.in");
ofstream out ("dijkstra.out");
vector<pair<int, int> > nodes[50005];
int cost[50005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater< > >pq;
void dijkstra(int start) {
    pq.push({0,start});
    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if(cost[top.second] != top.first)
            continue;
        for(auto it: nodes[top.second]) {
            if(it.second + cost[top.second] < cost[it.first]) {
                cost[it.first] = it.second + cost[top.second];
                pq.push({cost[it.first], it.first});
            }
        }
    }
}
int main() {
    int n,m;
    in >> n >> m;
    for(int i=1; i<=m;++i) {
        int u,v,coost;
        in >> u >>v >> coost;
        nodes[u].push_back({v, coost});
    }
    for(int i=2;i<=n;++i) {
        cost[i] = 1e9;
    }
    cost[1]=0;
    dijkstra(1);
    for(int i=2;i<=n;++i) {
        if(cost[i] == 1e9) {
            cost[i]=0;
        }
        out << cost[i] << " ";
    }
    return 0;
}