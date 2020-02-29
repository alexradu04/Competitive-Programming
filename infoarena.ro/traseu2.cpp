#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Gigel {
public:
    int x,i,j;
    bool operator< (const Gigel a) const {
        return x<a.x;
    }
};
vector<Gigel>coordinates;
int main() {
    freopen("traseu2.in","r",stdin);
    freopen("traseu2.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            string s;
            cin >> s;
            if(s == "#")
                continue;
            int x = 0;
            for(auto i : s)
                x = x * 10 + i - '0';
            Gigel aux;
            aux.x=x;
            aux.i=i;
            aux.j=j;
            coordinates.emplace_back(aux);
        }
    }
    n=coordinates.size();
    sort(coordinates.begin(),coordinates.end());
    for(int i=1;i<n;++i) {
        if(abs(coordinates[i].i-coordinates[i-1].i) > 1  ||  abs(coordinates[i].j-coordinates[i-1].j) >1) {
            printf("Nu exista solutie!\n");
            return 0;
        }
    }
    printf("Exista solutie!\n");
    printf("%d\n",n);
    for(int i=0;i<n;++i) {
        printf("%d %d %d\n",coordinates[i].i,coordinates[i].j,coordinates[i].x);
    }
    return 0;
}
