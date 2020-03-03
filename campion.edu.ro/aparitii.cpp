#include <cstdio>
#include <algorithm>

using namespace std;
int digits[15];
int nrcif(long long x) {
    int ret=0;
    do{
        ret++;
        x/=10;
    }while(x);
    return ret;
}
void putDigitsInVector (int x) {
    do {
        digits[++digits[0]]=x%10;
        x/=10;
    } while (x);
    reverse(digits+1,digits+digits[0]+1);
}
bool hask (int x, int k) {
    do {
        if(x%10==k)
            return true;
        x/=10;
    }   while(x);
    return false;
}
int main() {
    freopen("aparitii.in","r",stdin);
    freopen("aparitii.out","w",stdout);
    int n,k;
    scanf("%d %d",&n,&k);
    int  ans=0;
    if(n<10)
        ans=1;
    else
    {
        while(!hask(n,k)) {
            n--;
        }
    }
    long long int lim=9;
    while (lim<n) {
        int apar=8;
        for(int i=1;i<nrcif(lim);++i) {
            apar=apar*9;
        }
        ans+=apar;
        lim=lim*10 + 9;
    }
    putDigitsInVector(n);
    for(int i=1;i<=digits[0];++i) {
        int apar=digits[i]- (digits[i]>k)- (i==1);
        if(apar==-1)
            continue;
        for(int j=i+1;j<=digits[0];++j)   {
            apar*=9;
        }
        ans+=apar;
        if(digits[i]==k)
            break;
    }
    printf("%d",n-ans);
    return 0;
}
