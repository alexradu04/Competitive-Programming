#include <fstream>
using namespace std;
#define SIGMA 3
class Trie {
    int val;
    Trie *son[SIGMA]{};
public:
    Trie() {
        val=0;
        for(auto & i : son) {
            i=nullptr;
        }
    }
    void add(int number, int level, int index) {
        if(level == 0) {
            this->val=index;
            return;
        }
        int adder= ((number >> level) & 1);
        if(this->son[adder] == nullptr) {
            this->son[adder] = new Trie();
        }
        this->son[adder]->add(number, level-1, index);
    }
    int query (int number, int level) {
        if(level == 0) {
            return this->val;
        }
        int currentBit = ((number >> level) & 1);
        if(this->son[!currentBit] != nullptr) {
            return this->son[!currentBit]->query(number, level-1);
        }
        return  this->son[currentBit]->query(number, level-1);
    }
};
int v[100005];
ifstream fin ("xormax.in");
ofstream fout ("xormax.out");
Trie *trie = new Trie();
int main() {
    int n;
    fin >> n;
    for(int i=1;i<=n;++i) {
        fin >> v[i];
        v[i] ^= v[i-1];
    }
    trie->add(v[1], 25, 1);
    int ans=0;
    int st=1;
    int dr=1;
    for(int i=2;i<=n;++i) {
        int leftMost = trie->query(v[i], 25);
        if(ans < (v[i] ^ v[leftMost])) {
            st=leftMost+1;
            dr=i;
            ans = (v[i] ^ v[leftMost]);
        }
        trie->add(v[i], 25, i);
    }
    fout << ans << " " << st << " " << dr << "\n";
    return 0;
}