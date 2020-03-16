#include <cstdio>
#include <cmath>

using namespace std;
long long gcdExtended(long long a, long long b, long long &x, long long &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = gcdExtended(b%a, a, x1, y1);

    x = y1 - (b/a) * x1;
    y = x1;
    return gcd;
}
int main() {
    long long n=1;
    while(true) {
        scanf("%lld",&n);
        if(n==0) break;
        long long c1,c2,n1,n2;
        scanf("%lld%lld%lld%lld",&c1,&n1,&c2,&n2);
        long long m1,m2;
        long long d=gcdExtended(n1,n2,m1,m2);
        if(n%d) {
            printf("failed\n");
            continue;
        }
        m1 *= n / d;
        m2 *= n / d;
        n2 /= d;
        n1 /= d;
        long long left = ceil(-(double) m1 / n2), right = floor((double) m2 / n1);
        if (left > right)
        {
            printf("failed\n");
            continue;
        }
        long long cost = c1 * n2 - c2 * n1,x,y;
        if (cost * left < cost * right)
            x = m1 + n2 * left, y = m2 - n1 * left;
        else
            x = m1 + n2 * right, y = m2 - n1 * right;
        printf("%lld %lld\n",x,y);
    }
    return 0;
}
