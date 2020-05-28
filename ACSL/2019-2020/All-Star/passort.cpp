#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <map>

char s[100];
char s1[100];
using namespace std;
map<char, int> pos;
map<char, int> frec;

void my_swap(char &a, char &b) {
    char aux = a;
    a = b;
    b = aux;
    return;
}
bool is_good(char ch){
    if('a'<=ch &&ch<='z')
        return 1;
    if('A'<=ch &&ch<='z')
        return 1;
    if('0'<=ch &&ch<='9')
        return 1;
    return 0;
}
int main() {
    int n;
    gets(s);
    //printf("%d",'-');
    for (int i = 0; i < strlen(s); ++i) {
        if (!is_good(s[i])) {
            for (int j = i; j < strlen(s); ++j) {
                s[j] = s[j + 1];
            }
            i--;
        }
    }
    for (int i = 0; i < strlen(s); ++i) {
        s1[i] = s[i];
    }
    sort(s1, s1 + strlen(s1));
    int flick = 0, cnt = 0;
//    printf("%s\n",s1);
    while (strcmp(s1, s)) {
        int st=0,dr=strlen(s)-1;
        for(int i=0;i<strlen(s);++i)
            if(s[i]!=s1[i]) {
                st=i;
                break;
            }
        for(int i=strlen(s)-1;i>=0;--i)
            if(s[i]!=s1[i]) {
                dr=i;
                break;
            }
        int poss = -1;
        if (flick) {
            char maxx = 0;
            for (int i = 0; i < strlen(s); ++i) {
                if (s1[i] != s[i]) {
                    if (maxx <= s1[i]) {
                        maxx = s1[i];
                        poss = i;
                    }
                }
            }
            int pw=0;
            for(int i=0;i<=dr;++i) {
                if(s[i]==maxx) {
                    pw=i;
                }
            }
            swap(s[pw],s[poss]);
        }
        if (!flick) {
            char minn = 126;
            for (int i = 0; i < strlen(s); ++i) {
                if (s1[i] != s[i]) {
                    if (minn > s1[i]) {
                        minn = s1[i];
                        poss = i;
                    }
                }
            }
            for(int i=st;i<strlen(s);++i) {
                if(s[i]==minn) {
                    swap(s[i],s[poss]);
                    break;
                }
            }
        }
        cnt++;
        flick = (!flick);
        //printf("%s\n",s);
    }
    printf("%d", cnt);
    return 0;
}
