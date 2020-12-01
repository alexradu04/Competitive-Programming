#include <fstream>
#include <queue>
#include <utility>

using namespace std;
int parc[180][180];
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool isValid(int i, int j) {
    return !(i < 1 || j < 1 || i > n || j > n || parc[i][j] == -1);
}
queue<pair<int, int> > bfsQueue;
ifstream in ("alee.in");
ofstream out ("alee.out");

void bfs() {
    while(!bfsQueue.empty()) {
        auto top = bfsQueue.front();
        bfsQueue.pop();
        for(int i=0;i<4;++i) {
            auto newTop= make_pair(top.first + dx[i], top.second + dy[i]);
            if(isValid(newTop.first, newTop.second) && parc[newTop.first][newTop.second] == 0) {
                parc[newTop.first][newTop.second]= parc[top.first][top.second] + 1;
                bfsQueue.push(newTop);
            }
        }

    }
}
int main() {
    in >> n >> m;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j)
//            parc[i][j] = 1e9;
//    }
    for (int i = 1; i <= m; ++i) {
        int x, y;
        in >> x >> y;
        parc[x][y] = -1;
    }
    int x1, x2, y1, y2;
    in >> x1 >> x2 >> y1 >>y2;
    bfsQueue.push(make_pair(x1,x2));
    bfs();
    out << parc[y1][y2] + 1;
    return 0;
}