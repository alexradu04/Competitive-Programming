#include <cstdio>
#include <unordered_map>
#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;
vector<int> firstRow;
vector<int> secondRow;
int main() {
    freopen("gr.in","r",stdin);
    freopen("gr.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        int x;
        scanf("%d",&x);
        firstRow.emplace_back(x);
    }
    for(int i=1;i<=n;++i) {
        int x;
        scanf("%d",&x);
        secondRow.emplace_back(x);
    }
    int ans=0,candidate=0;
    for(auto it: firstRow) {
        if(it== candidate) {
            candidate = 0;
        } else if(it<candidate) {
            ans=max(ans,it);
        } else {
            ans=max(ans,candidate);
            candidate=it;
        }
    }
    ans=max(ans,candidate);
    candidate=0;
    for(auto it: secondRow) {
        if(it== candidate) {
            candidate = 0;
        } else if(it<candidate) {
            ans=max(ans,it);
        } else {
            ans=max(ans,candidate);
            candidate=it;
        }
    }
    ans=max(ans,candidate);
    printf("%d",ans);
    return 0;
}
