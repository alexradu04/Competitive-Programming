#include <cstdio>
#include <iostream>
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        int newNumber=(a/b)*b +b;
        printf("%d\n",(a%b) ? newNumber-a :0);   }
    return 0;
}
