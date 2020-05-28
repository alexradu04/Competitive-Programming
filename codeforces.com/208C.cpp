#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#define NR_MARE (1<<30)
using namespace std;
int dp[3][105]; ///DISTANTA
bool vis[3][105];
long long nrPos[3][105];///nr de moduri
vector<int> G[105];
queue<int> bfsQueue;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <=m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = dp[1][i] = NR_MARE;
    }
    vis[0][1] = 1;
    dp[0][1] = 0;
    nrPos[0][1] = 1;
    bfsQueue.push(1);
    while (!bfsQueue.empty()) {
        int currNode = bfsQueue.front();
        bfsQueue.pop();
        for (auto u:G[currNode]) {
            if (!vis[0][u]) {
                vis[0][u] = 1;
                dp[0][u] = dp[0][currNode] + 1;
                nrPos[0][u] = nrPos[0][currNode];
                bfsQueue.push(u);
            } else if (dp[0][u] == dp[0][currNode] + 1) {
                nrPos[0][u] += nrPos[0][currNode];
            }
        }
    }
    vis[1][n] = 1;
    dp[1][n] = 0;
    nrPos[1][n] = 1;
    bfsQueue.push(n);
    while (!bfsQueue.empty()) {
        int currNode = bfsQueue.front();
        bfsQueue.pop();
        for (auto u:G[currNode]) {
            if (!vis[1][u]) {
                vis[1][u] = 1;
                dp[1][u] = dp[1][currNode] + 1;
                nrPos[1][u] = nrPos[1][currNode];
                bfsQueue.push(u);
            } else if (dp[1][u] == dp[1][currNode] + 1) {
                nrPos[1][u] += nrPos[1][currNode];
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[0][i] + dp[1][i] == dp[0][n]) {
            if (i == 1 || i == n)
                ans = max(ans, nrPos[0][i] * nrPos[1][i]);
            else
                ans = max(ans, 2 * nrPos[0][i] * nrPos[1][i]);

        }
    }
    cout << fixed << setprecision(12) <<1.0 * ans / nrPos[0][n];
    return 0;
}