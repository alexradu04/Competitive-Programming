#include <bits/stdc++.h>

using namespace std;

string expression;
unordered_map<char, int> fact;
unordered_map<long long, int> firstHalf;
int main() {
    freopen("eq4.in", "r", stdin);
    freopen("eq4.out", "w", stdout);
    int cer;
    int a, b;
    long long res;
    cin >> cer;
    cin >> expression;
    cin >> a >> b >> res;
    int num = 0, sign = 1;
    bool hasNumber = false;
    fact['@'] = 0;
    fact['x'] = 0;
    fact['y'] = 0;
    fact['z'] = 0;
    fact['t'] = 0;
    for (int i = 0; i < expression.size(); ++i) {
        if (expression[i] == '+' || expression[i] == '-') {
            num = 0;
            hasNumber = false;
            if (expression[i] == '+') {
                sign = 1;
            } else
                sign = -1;
            continue;
        }
        if (isdigit(expression[i])) {
            num = num * 10 + sign * (expression[i] - '0');
            hasNumber = true;
        }
        if (isalpha(expression[i])) {
            if (!hasNumber)
                num = sign;
            fact[expression[i]] += num;
            continue;
        }
        if (expression[i + 1] == '+' || expression[i + 1] == '-' || i == expression.size() - 1) {
            if (!hasNumber)
                num = sign;
            fact['@'] += num;
        }
    }
    if (cer == 1) {
        long long sum = 0;
        for (auto it: fact) {
            sum += it.second;
        }
        cout << sum;
        return 0;
    }
    int cnt = 0;
    for (int valx = a; valx <= b; ++valx) {
        for (int valy = a; valy <= b; ++valy) {
            long long sum = 0;
            sum += fact['@'];
            sum += fact['x'] * valx;
            sum += fact['y'] * valy;
            firstHalf[sum]++;
        }
    }
    for (int valz = a; valz <= b; ++valz) {
        for (int valt = a; valt <= b; ++valt) {
            long long sum = 0;
            sum += fact['z'] * valz;
            sum += fact['t'] * valt;
            if(firstHalf.find(res-sum)!= firstHalf.end())
                cnt+=firstHalf[res-sum];
        }
    }
    cout << cnt;
    return 0;
}