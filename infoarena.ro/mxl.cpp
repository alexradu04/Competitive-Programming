#include <bits/stdc++.h>
#define int long long
using namespace std;
map<pair<int, int>, string> mp;
int answer[50][40];

int decodeExpr(int x, int y, string expr) {
    if(answer[x][y] != 0 )
        return answer[x][y];
    if (expr.empty()) {
        answer[x][y] = 0;
        return 0;
    }
    if (expr[0] != '=') {
        int aux = 0;
        for (char i : expr) {
            aux = aux * 10 + i - '0';
        }
        answer[x][y] = aux;
        return aux;
    }
    vector<int> numExpr;
    numExpr.push_back(-5);
    int curr = 0;
    for (int i = 1; i < expr.size(); ++i) {
        if (isdigit(expr[i])) {
            curr = curr* 10 + expr[i]-'0';
        } else {
            numExpr.push_back(curr);
            curr=0;
            if(expr[i] == ':')
                numExpr.push_back(-1);
            else
                numExpr.push_back(-2);
        }
    }
    if(curr)
        numExpr.push_back(curr);
//    for(auto it: numExpr) {
//        cerr << it << " ";
//    }
//    cerr <<"\n";
    map<int, bool> positions;
    vector<int> terms;
    for (int i = 1; i < numExpr.size(); ++i) {
        if (numExpr[i] == -1) {
            positions[i - 1] = positions[i] = positions[i + 1] = true;
            terms.push_back(decodeExpr(numExpr[i - 1] , numExpr[i + 1],
                                       mp[{numExpr[i - 1] , numExpr[i + 1] }]));
        }
    }
    for (int i = 1; i < numExpr.size(); ++i) {
        if (!positions[i] && numExpr[i]>0)
            terms.push_back(numExpr[i] );
    }
    int aux = 0;
    for (auto it: terms) {
        aux += it;
    }
    answer[x][y] = aux;
    return aux;
}

int32_t main() {
    freopen("mxl.in", "r", stdin);
    freopen("mxl.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int lin, col;
        string kekxpression;
        cin >> lin >> col >> kekxpression;
        mp[make_pair(lin, col)] = kekxpression;
        //cerr << lin<< " " <<col <<" " <<  kekxpression << "\n";
    }
    //cerr<<mp[{1,6}].size();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (answer[i][j] == 0) {
                decodeExpr(i, j, mp[{i, j}]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}