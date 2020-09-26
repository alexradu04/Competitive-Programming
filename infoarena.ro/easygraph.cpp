#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream in("easygraph.in");
ofstream out("easygraph.out");
int nodeVals[15005];
long long dp[15005];
vector<int> edges[15005];
bool seen[15005];
vector<int> dfsorder;

void dfs(int x) {
    seen[x] = true;
    for (auto node : edges[x]) {
        if (!seen[node]) {
            dfs(node);
        }
    }
    dfsorder.emplace_back(x);
}

int main() {
    int T;
    in >> T;
    for (int idx = 1; idx <= T; ++idx) {
        int n, m;
        in >> n >> m;
        for (int i = 1; i <= n; ++i) {
            in >> nodeVals[i];
            dp[i] = nodeVals[i];
            edges[i].clear();
            seen[i] = false;
        }
        for (int i = 1; i <= m; ++i) {
            int x, y;
            in >> x >> y;
            edges[x].emplace_back(y);
        }
        for (int i = 1; i <= n; ++i) {
            if (!seen[i])
                dfs(i);
        }
        long long ans = -10000000000000;
        for (int i = dfsorder.size() - 1; i >= 0; --i) {
            for (auto j : edges[dfsorder[i]]) {
                dp[j] = max(dp[j], dp[dfsorder[i]] + nodeVals[j]);
                ans = dp[j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dp[i]);
        }
        out << ans << "\n";
    }
    return 0;
}
