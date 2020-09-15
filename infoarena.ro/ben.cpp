
#include <fstream>
#define MOD 32173
using namespace std;
ifstream cin("ben.in");
ofstream cout("ben.out");
int p[30011];

class Masini {
public:
    int start, finish;
};

Masini a[30011];

int main() {
    int n, maxx = 0, pmaxx = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].start >> a[i].finish;
        p[a[i].start]++;
        p[a[i].finish + 1]--;
        pmaxx = max(pmaxx, a[i].finish + 1);
    }
    for (int i = 2; i <= pmaxx; ++i) {
        p[i] = p[i] + p[i - 1];
        maxx = max(p[i], maxx);
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans = (ans * (maxx - p[a[i].start] + 1)) % MOD;
        p[a[i].start]--;
    }
    cout << maxx << ' ' << ans << '\n';
    return 0;
}