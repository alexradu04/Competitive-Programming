#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<int> constructLISVectors(const vector<int>& els) {
    vector<int> lis_stack ;
    lis_stack.emplace_back(2e9);
    vector<int> answer;

    auto BinarySearch = [&](int val) {
        int n = (int)lis_stack.size();
        int ans = 0;
        for (int p = 20; p >= 0; p -= 1) {
            if ((1 << p) + ans < n) {
                if (lis_stack[(1 << p) + ans] <= val) {
                    ans += (1 << p);
                }
            }
        }

        return ans;
    };

    for (auto itr : els) {
        int pos = BinarySearch(itr);
        pos += 1;

        if ((int)lis_stack.size() == pos) {
            lis_stack.push_back(0);
        }

        lis_stack[pos] = itr;
        answer.push_back(pos);
    }

    return answer;
}
vector<pair<int,int> > specialCoordinates;
vector<int> LISList;
vector<int> reversedLISList;
map<int,int>seenLeftSizes;
int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=k;++i) {
        int row,collumn;
        scanf("%d %d",&row,&collumn);
        specialCoordinates.emplace_back(make_pair(row,collumn));
    }
    sort(specialCoordinates.begin(), specialCoordinates.end());
    for(int i=0;i<k;++i) {
        LISList.emplace_back(specialCoordinates[i].second);
        reversedLISList.emplace_back((-1)*specialCoordinates[i].second);
    }
    reverse(reversedLISList.begin(),reversedLISList.end());
    auto prefixLIS= constructLISVectors(LISList);
    auto suffixLIS= constructLISVectors(reversedLISList);
    reverse(suffixLIS.begin(),suffixLIS.end());
    int ans=0,requiredSize=0;
    for(int i=0;i<specialCoordinates.size();++i) {
        if(prefixLIS[i]+suffixLIS[i]-1> requiredSize)
            requiredSize=prefixLIS[i]+suffixLIS[i]-1;
    }
    for(int i=0;i<specialCoordinates.size();++i) {

        int leftLISSize=prefixLIS[i];
        int rightLISSize=suffixLIS[i];
        if(leftLISSize + rightLISSize -1 == requiredSize) {
            seenLeftSizes[leftLISSize]++;
            //ans++;
        }
    }
    for(auto it: seenLeftSizes) {
        if(it.second==1) {
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
