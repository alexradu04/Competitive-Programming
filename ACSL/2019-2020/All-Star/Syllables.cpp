#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define ee for
typedef std::string xukun;
int PUNBARAWOW[6969];
std::vector<xukun> horgalees, RAMATAMASWAP;
int SUMFORVOCALALOL[6969];
void horgalee();
bool ishorgale(xukun x);
void sufixe();
bool isSuffix(xukun x);
void START();
bool isVowel(char x);
bool isConsCombo(char a, char b);
void horgale(xukun &cuvantPentruProblema, xukun &pref);
void suffix(xukun &cuvantPentruProblema, xukun &suff);
bool checkIfSilaba(xukun cuvantPentruProblema, int JOEMAMAEDITION2);
const xukun SILABA = (xukun)("|");
bool check2Cons(xukun cuvantPentruProblema, int JOEMAMAEDITION2);
xukun solve(xukun &cuvantPentruProblema);
int main() {
    horgalee();sufixe();
    xukun cuvantPentruProblema; std::cin>>cuvantPentruProblema;
    xukun ans=solve(cuvantPentruProblema);
    int solutiondepaparaztion=0;
    ee (int HEHE=0;HEHE<ans.size();++HEHE) {
        solutiondepaparaztion += (ans[HEHE]== '|') * HEHE ;
    }
    std::cout<<solutiondepaparaztion;
}
bool check2Cons(xukun cuvantPentruProblema,int JOEMAMAEDITION2) {
    if (isVowel(cuvantPentruProblema[JOEMAMAEDITION2])==1) {return 0;}
    if (JOEMAMAEDITION2<1) {return 0;}
    char left=cuvantPentruProblema[JOEMAMAEDITION2-1];
    if (isVowel(left)==1) {return 0;}
    if (isConsCombo(left,cuvantPentruProblema[JOEMAMAEDITION2])) {return 0;}
    if (SUMFORVOCALALOL[JOEMAMAEDITION2+1]==0) {return 0;}
    if (JOEMAMAEDITION2>2) {
        char sl=cuvantPentruProblema[JOEMAMAEDITION2-2];
        if (isConsCombo(sl,left)) {
            if (SUMFORVOCALALOL[0]-SUMFORVOCALALOL[JOEMAMAEDITION2-2]<=0) {return 0;}
        }
    } else {
        if (SUMFORVOCALALOL[0]-SUMFORVOCALALOL[JOEMAMAEDITION2-1]<=0) {return 0;}
    }
    return 1;
}
void horgalee() {
    horgalees.push_back((xukun)"co");
    horgalees.push_back((xukun)"re");
    horgalees.push_back((xukun)"un");
    horgalees.push_back((xukun)"de");
    horgalees.push_back((xukun)"pre");
    horgalees.push_back((xukun)"dis");
}
bool ishorgale(xukun x) {
    ee (auto it : horgalees) {
        if (it==x) {return 1;}
    }
    return 0;
}

void sufixe() {
    RAMATAMASWAP.push_back((xukun)"less");
    RAMATAMASWAP.push_back((xukun)"ment");
    RAMATAMASWAP.push_back((xukun)"age");
    RAMATAMASWAP.push_back((xukun)"ing");
    RAMATAMASWAP.push_back((xukun)"ful");
}
bool isSuffix(xukun x) {
    std::reverse(begin(x), end(x));
    ee (auto it : RAMATAMASWAP) {
        if (it==x) {return 1;}
    }
    return 0;
}
bool isVowel(char x) {
    return (x=='a'||x=='e'||x=='i'||x=='o'||x=='u');
}
bool isConsCombo(char a, char b) {
    return(a=='c'&&b=='h')||(a=='c'&&b=='k')||(a=='p'&&b=='h')||(a=='s'&&b=='h')||(a=='t'&&b=='h')||(a=='w'&&b=='h')||(a=='w'&&b=='r');
}
void horgale(xukun &cuvantPentruProblema, xukun &pref) {
    xukun pre("");
    int i;
    ee (i=0;i<cuvantPentruProblema.size();++i) {
        pre+=cuvantPentruProblema[i];
        if (ishorgale(pre)) {
            pref=pre;
            cuvantPentruProblema.erase(cuvantPentruProblema.begin(),cuvantPentruProblema.begin()+i+1);
            return;
        }
    }
}
xukun solve(xukun &cuvantPentruProblema) {
    xukun pref(""),suff("");
    horgale(cuvantPentruProblema,pref);
    suffix(cuvantPentruProblema,suff);
    ee (int i=(int)cuvantPentruProblema.size()-1; i>=0;--i) {
        SUMFORVOCALALOL[i]=SUMFORVOCALALOL[i+1]+isVowel(cuvantPentruProblema[i]);
    }
    int vowels=0;
    ee (int i=0;i<cuvantPentruProblema.size();++i) {
        if (isVowel(cuvantPentruProblema[i])==1) {
            vowels++;
        } else if (vowels>0&&SUMFORVOCALALOL[i]>0) {
            if (checkIfSilaba(cuvantPentruProblema,i)) {PUNBARAWOW[i]=1;vowels=0;}
        }
        if (check2Cons(cuvantPentruProblema,i)) {PUNBARAWOW[i]=1;}
    }
    xukun WABALABADABDAB("");
    if (pref!="") {
        WABALABADABDAB+=pref;WABALABADABDAB+=SILABA;
    }
    ee (int i=0;i<cuvantPentruProblema.size();++i) {
        if (PUNBARAWOW[i]==1) {
            WABALABADABDAB+=SILABA;
        }
        WABALABADABDAB+=cuvantPentruProblema[i];
    }
    if (suff!="") {
        WABALABADABDAB+=SILABA;WABALABADABDAB+=suff;
    }
    return WABALABADABDAB;
}

void suffix(xukun &cuvantPentruProblema, xukun &suff) {
    xukun suf("");
    int i;
    ee (i=(int)cuvantPentruProblema.size()-1;i>=0;--i) {
        suf+=cuvantPentruProblema[i];
        if (isSuffix(suf)) {
            reverse(begin(suf),end(suf));
            suff=suf;
            cuvantPentruProblema.erase(cuvantPentruProblema.begin()+i, cuvantPentruProblema.end());
            return;
        }
    }
}
bool checkIfSilaba(xukun cuvantPentruProblema, int JOEMAMAEDITION2) {
    int n=(int)cuvantPentruProblema.size()-1;
    if (JOEMAMAEDITION2+1>n) {
        return 0;
    }
    if (JOEMAMAEDITION2+1<=n&&isVowel(cuvantPentruProblema[JOEMAMAEDITION2+1])) {
        return 1;
    }
    char fi=cuvantPentruProblema[JOEMAMAEDITION2];
    char se=cuvantPentruProblema[JOEMAMAEDITION2 + 1];
    bool combo=isConsCombo(fi, se);
    if (combo==0) {
        return 0;
    }
    if (JOEMAMAEDITION2+2>n) {
        return 0;
    }
    char nfi=cuvantPentruProblema[JOEMAMAEDITION2+2];
    if (isVowel(nfi)==1) {
        return 1;
    }
    return 0;
}
