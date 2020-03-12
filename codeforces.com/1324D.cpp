#include <cstdio>
#include <algorithm>

using namespace std;
class Preference {
public:
    int teachers,children;
    bool operator < (const Preference a) const {
        return this->teachers - this->children < a.teachers-a.children;
    }
};
Preference preferences[200005];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d",&preferences[i].teachers);
    }
    for(int i=1;i<=n;++i) {
        scanf("%d",&preferences[i].children);
    }
    sort(preferences+1,preferences+n+1);
    long long correctPairs=0;
    for(int i=1;i<=n;++i) {
        int neededQuality=0-(preferences[i].teachers-preferences[i].children);
        int st=1,dr=n;
        int ans=n+1;
        while(st<=dr) {
            int mid=(st+dr)/2   ;
            if(preferences[mid].teachers-preferences[mid].children >neededQuality) {
                ans=mid;
                dr=mid-1;
            } else
                st=mid+1;
        }
        correctPairs+= (n - ans + 1) + ((i >= ans) ? -1 : 0);
    }
    printf("%lld", correctPairs/2);
    return 0;
}
