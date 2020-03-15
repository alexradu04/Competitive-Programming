#include <cstdio>
#include <string>
#include <map>
#include <iostream>

using namespace std;
long long factorial[25];
int main() {
    factorial[0]=1;
    for(int i=1;i<=20;++i) {
        factorial[i]=factorial[i-1]*i;
    }
    int n;
    scanf("%d",&n);
    for(int dataSet=1;dataSet<=n;++dataSet) {
        string word;
        //scanf("%s",word.c_str()); scanf nu functioneaza cu strcturi de date c++11
        cin>>word;
        map<char,int>characterFrequency;
        for(char i : word) {
            characterFrequency[i]++;
        }
        long long numberOfCombinations=factorial[word.size()];
        for(char i='A';i<='Z';++i) {
            numberOfCombinations/=factorial[characterFrequency[i]];
        }
        printf("Data set %d: %lld\n",dataSet,numberOfCombinations);
    }
    return 0;
}
