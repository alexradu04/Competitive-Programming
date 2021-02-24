#include <fstream>
#include <algorithm>

using namespace std;

char st[100005];
int top = 0;
ifstream cin("charlie.in");
ofstream cout("charlie.out");

int main() {
    int reqFlag;
    cin >> reqFlag;
    string s;
    cin >> s;
    if (reqFlag == 1) {
        int cnt = 1;
        int ans = 0;
        for (int i = 1; i < s.size() - 1; ++i) {
            if (s[i] < s[i - 1] && s[i] < s[i + 1]) {
                cnt += 2;
                i++;
                ans = max(ans, cnt);
                continue;
            }
            cnt = 1;
            ans = max(ans, cnt);
        }
        ans = max(ans, cnt);
        cout << ans << "\n";
        return 0;
    }
    int cost = 0;
    for (char & i : s) {
        while (top > 1 && st[top - 1] > st[top] && st[top] < i) {
            cost += max(st[top - 1], i) - 'a' + 1;
            top--;
        }
        st[++top] = i;
    }
    string printBuff;
    while (top > 0) {
        printBuff += st[top];
        top--;
    }
    for (int i = printBuff.size() - 1; i >= 0; --i) {

        cout << printBuff[i];
    }
    cout << "\n" << cost;
}