#include <cstdio>
int v[50005];
int a[50005];
int b[50005];
int main() {
    int tc;
    scanf("%d",&tc);
    for(int idx=1;idx<=tc;++idx) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%1d", &v[i]);
        }
        a[1] = b[1] = 1;
        bool ok = false;
        for (int i = 2; i <= n; ++i) {
            if (!ok && v[i] == 2) {
                a[i] = b[i] = 1;
                continue;
            }
            if (!ok && v[i] == 0) {
                a[i] = 0;
                b[i] = 0;
                continue;
            }
            if (!ok) {
                ok = true;
                if (v[i] == 1) {
                    a[i] = 1;
                    b[i] = 0;
                }
                continue;
            }
            a[i] = 0;
            b[i] = v[i];
        }
        for (int i = 1;i <= n; ++i) printf("%d", a[i]);
        printf("\n");
        for (int i = 1;i <= n; ++i) printf("%d", b[i]);
        printf("\n");
    }
    return 0;
}
