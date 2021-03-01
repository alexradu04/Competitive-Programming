#include <bits/stdc++.h>
using namespace std;
ifstream fin ("rover.in");
ofstream fout ("rover.out");

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int mat[505][505];
int isStable[505][505];
int score[505][505];
deque<pair<int, int> > bfsQueue;//more like bfsdeque haha I wanna kill myself
int n;
inline void makeBfsMat(int g) {
    while(!bfsQueue.empty())
        bfsQueue.pop_back();
    bfsQueue.push_back(make_pair(1, 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            score[i][j]=0;
            if (mat[i][j] < g) {
                isStable[i][j] = 0;
            } else
                isStable[i][j] = 1;
        }
    }
    score[1][1]=1;
}
bool inBounds (pair<int, int> a) {
    return a.first > 0 && a.first <=n && a.second > 0 && a.second <= n;
}
int checkBfs() {
    while(!bfsQueue.empty()) {
        auto top = bfsQueue.front();
        bfsQueue.pop_front();
        for(int i=0;i<4;++i) {
            auto it = make_pair(top.first+dx[i], top.second+dy[i]);
            if(score[it.first][it.second] || !inBounds(it))
                continue;
            score[it.first][it.second] = score[top.first][top.second] + !isStable[it.first][it.second];
            if(isStable[it.first][it.second] != 1)
                bfsQueue.push_back(it);
            else
                bfsQueue.push_front(it);
        }
    }
    return score[n][n]-1;
}

int main() {
    int cer, g;
    fin >> cer >> n;
    if (cer == 1) {
        fin >> g;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            fin >> mat[i][j];
        }
    }
    if (cer == 1) {
        makeBfsMat(g);
        fout << checkBfs() << "\n";
        return 0;
    }
    int st = 1, dr = 10005;
    int ans=10000;
    while (st <= dr) {
        int mid = (st + dr) / 2;
        makeBfsMat(mid);
        if(checkBfs() > 0) {
            dr=mid-1;
        }else {
            ans=mid;
            st=mid+1;
        }
    }
    fout << ans << "\n";
    return 0;
}