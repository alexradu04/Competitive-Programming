#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int digits[1000005];
int main() {
    freopen("sstabil.in","r",stdin);
    freopen("sstabil.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d",&digits[i]);
    }
    reverse(digits+1,digits+n+1);
    int sum=digits[1];
    vector<int>newNumber;
    for(int i=2;i<=n;++i) {
        if(sum<=9) {
            sum+=digits[i];
        }
        while(sum>=10) {
            int j=i,newSum=0;
            while(newSum<=9) {
                newSum+=digits[j];
                j--;
            }
            j++;
            newSum-=digits[j];
            newNumber.emplace_back(sum-newSum);
            sum=newSum;
            digits[i]=newSum;
        }
    }
    newNumber.push_back(sum);
    reverse(newNumber.begin(), newNumber.end());
    for(auto it:newNumber) {
        printf("%d",it);
    }
    return 0;
}
