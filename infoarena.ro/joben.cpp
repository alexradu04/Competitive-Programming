#include <fstream>
#include <algorithm>

using namespace std;
int freq1[100];
int freq2[100];
ifstream cin ("joben.in");
ofstream cout ("joben.out");
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) {
        string s1;
        string s2;
        cin >> s1;
        cin >> s2;
        for(int j=0;j<s1.size();++j) {
            freq1[s1[j]-'a']++;
            freq2[s2[j]-'a']++;
        }
        sort(freq1, freq1+27);
        sort(freq2, freq2+27);
        bool isValid= true;
        for(int j=0;j<=26;++j) {
            if(freq1[j]!=freq2[j]) {
                isValid=false;
            }
            freq1[j]=freq2[j]=0;
        }
        cout <<(isValid ? "DA" : "NU") << "\n";
    }
    return 0;
}