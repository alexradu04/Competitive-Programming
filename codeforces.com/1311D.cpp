#include <cstdio>
#include <cstdlib>
using namespace std;
class Answer {
public:
    int a,b,c;
};
int main() {
    int tc;
    scanf("%d",&tc);
    for(int index=1;index<=tc;++index) {
        int originalA,originalB,originalC;
        Answer answerGroup;
        int minn=1e9;
        scanf("%d %d %d",&originalA, &originalB ,&originalC);
        for(int a=1;a<=2*originalA;++a) {
            for(int b=a;b<=50000;b+=a) {
                int c1=(originalC/b)*b;
                int c2=(originalC/b)*b +b;

                int c;
                if(c1>=b) {
                    (abs(originalC-c1) < abs(originalC-c2)) ? c=c1 : c=c2;
                } else
                    c=c2;
                int ans=abs(a-originalA) + abs(b-originalB) + abs(c-originalC);
                if(ans<minn) {
                    minn=ans;
                    answerGroup.a=a;
                    answerGroup.b=b;
                    answerGroup.c=c;
                }
            }
        }
        printf("%d\n%d %d %d\n",minn,answerGroup.a,answerGroup.b,answerGroup.c);
    }
    return 0;
}
