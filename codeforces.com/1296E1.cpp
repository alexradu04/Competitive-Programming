#include <cstdio>
#include <utility>
#include <map>
using namespace std;
char v[205];
int color[205];
map<pair<int,int>,bool> differences;
int main() {
    int n;
    scanf("%d\n",&n);
    for(int i=1;i<=n;++i) {
        scanf("%c",&v[i]);
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<i;++j) {
            if(v[j]>v[i]) {
                differences[make_pair(i,j)]=true;
                differences[make_pair(j,i)]=true;
            }
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            for(int k=1;k<=n;++k) {
                if(differences[make_pair(i,j)] && differences[make_pair(k,j)] && differences[make_pair(i,k)]) {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(differences[make_pair(i,j)]) {
                color[j]=1-color[i];
            }
        }
    }
    for(int i=1;i<=n;++i) {
        printf("%d",color[i]);
    }
    return 0;
}
