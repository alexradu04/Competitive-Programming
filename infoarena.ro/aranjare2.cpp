#include <cstdio>
#include <algorithm>

using namespace std;

int actualPosition[200005], positionNeeded[200005];
int main()
{
    freopen("aranjare2.in","r",stdin);
    freopen("aranjare2.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        actualPosition[i]=i;
        positionNeeded[i]=2*i-1;
    }
    for(int i=n+1;i<=2*n;i++)
    {
        actualPosition[i]=i;
        positionNeeded[i]=2*(i-n);
    }

    for(int i=1;i<=2*n;i++)
        if(i!=positionNeeded[actualPosition[i]])
        {
            printf("%d %d\n",i,positionNeeded[actualPosition[i]]);
            swap(actualPosition[i],actualPosition[positionNeeded[actualPosition[i]]]);
            i--;
        }

    return 0;
}