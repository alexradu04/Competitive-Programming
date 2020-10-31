
#include <iostream>
#include "fstream"
#include "string"

#define SIGMA 26
using namespace std;

class Trie {
    int val, noOfSons;
    Trie *son[SIGMA]{};

public:
    void add(char *s) {
        if (*s == 0) {
            this->val++;
            return;
        }
        if (this->son[*s - 'a'] == nullptr) {
            this->son[*s - 'a'] = new Trie();
            this->noOfSons++;
        }
        this->son[*s - 'a']->add(s + 1);
    }

    bool del(char *s, int depth=0) {
        if (*s == 0) {
            this->val--;
        } else if ((*this->son[*s - 'a']).del(s + 1, depth+1)) {
            this->son[*s - 'a'] = nullptr;
            this->noOfSons--;
        }
        if (this->val == 0 && this->noOfSons == 0 && depth>0) {
            delete this;
            return true;
        }
        return false;
    }

    int query1(char *s) {
        if (*s == 0)
            return this->val;
        if (this->son[*s - 'a']) {
            return this->son[*s - 'a']->query1(s + 1);
        }
        return 0;
    }

    int query2(char *s, int k = 0) {
        if (*s == 0 || this->son[*s - 'a'] == nullptr)
            return k;
        return this->son[*s - 'a']->query2(s + 1, k + 1);
    }

    Trie() {
        val = 0;
        noOfSons = 0;
        for (auto &i : son) {
            i = nullptr;
        }
    }
};

char line[50];
ifstream fin("trie.in");
ofstream fout("trie.out");
Trie *trie = new Trie();

int main() {
    fin.getline(line, 100);
    while (*line != 0) {
        switch (line[0]) {
            case '0' :
                trie->add(line + 2);
                break;
            case '1' :
                trie->del(line + 2);
                break;
            case '2' :
                fout << trie->query1(line + 2) << "\n";
                break;
            case '3' :
                fout << trie->query2(line + 2) << "\n";
                break;
        }
        fin.getline(line, 100);
    }
    return 0;
}