#include <cstdio>
using namespace std;
int cer,n,v;
int cubeFace1[205][205];
int cubeFace2[205][205];
bool prime[8000010];
void ciur() {

    prime[1]=1 ;
    int lim=8000005;
    for(int i=2;i<=lim;++i) {
        if(!prime[i]) {
            for(int j=i*2;j<=lim;j+=i) {
                prime[j]=true;
            }
        }
    }
}
void incrementPosition(int &x, int &y) {
    if (x==0&&y==1) {
        x=1;y=0;
    } else if (x==1&&y==0) {
        x=0;y=-1;
    } else if (x==0&&y==-1) {
        x=-1;y=0;
    } else if (x==-1&&y==0) {
        x=0;y=1;
    }
}
void fillCube1(int n) {
    int start=1 ;
    int line=1, column=1;
    int lineIndicator=0,columnIndicator=1;
    for (;start<=n*n;) {
        cubeFace1[line][column] = start ++;
        line += lineIndicator;
        column += columnIndicator;
        if (cubeFace1[line][column]) {
            line -= lineIndicator;
            column -= columnIndicator;
            incrementPosition(lineIndicator, columnIndicator);
            line += lineIndicator;
            column += columnIndicator;
        }
    }
}
void fillCube2(int n) {
    int start=n;
    int line=1, column=1;
    int lineIndicator=0,columnIndicator=1;
    for (;start>n/2;) {
        cubeFace2[line][column] = start --;
        line += lineIndicator;
        column += columnIndicator;
        if (cubeFace2[line][column]) {
            line -= lineIndicator;
            column -= columnIndicator;
            incrementPosition(lineIndicator, columnIndicator);
            line += lineIndicator;
            column += columnIndicator;
        }
    }
}
void coverCubeFirstReq () {
    int cubeArea=n*n;
    int level=v/cubeArea;
    level+=(v%cubeArea != 0);
    v%=cubeArea;
    if(v==0) v=cubeArea;
    if(level %2) {
        fillCube1(n);
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=n;++j) {
                if(cubeFace1[i][j]==v) {
                    printf("%d %d %d",i,j,level);
                    return;;
                }
            }
        }
    }else {
        fillCube2(2*cubeArea);
        v+=cubeArea;
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=n;++j) {
                if (cubeFace2[i][j]==v) {
                    printf("%d %d %d", i, j, level);
                    return;
                }
            }
        }
    }
}
void coverCubeSecondReq() {
    ciur() ;
    fillCube1(n) ;
    fillCube2(2 * n * n) ;

    int ans1, ans2, ans3, ans4;
    ans1=ans2=ans3=ans4=0;
    for (int i=1;i<=n;i+=2) {
        for (int j=1;j<=n;++j) {
            ans4+= !prime[cubeFace1[j][1] + n*n*(i-1)];
            ans1+= !prime[cubeFace1[1][j] + n*n*(i-1)];
            ans3+= !prime[cubeFace1[n][j] + n*n*(i-1)];
            if (!prime[cubeFace1[j][n] + n*n*(i-1)]) {
                ans2++;
            }
        }
    }
    for (int i=2;i<=n;i+=2) {
        for (int j=1;j<=n;++j) {
            ans4+= !prime[cubeFace2[j][1] + n*n*(i-2)];
            ans1+= !prime[cubeFace2[1][j] + n*n*(i-2)];
            ans3+= !prime[cubeFace2[n][j] + n*n*(i-2)];
            if (!prime[cubeFace2[j][n] + n*n*(i-2)]) {
                ans2++;
            }
        }
    }
    printf( "%d\n%d\n%d\n%d", ans1, ans2, ans3, ans4) ;
}
int main() {
    freopen("cub2.in","r",stdin);
    freopen("cub2.out","w",stdout);
    scanf("%d %d %d",&cer,&n,&v);
    for (int i = 1 ; i <= n ; ++ i) {
        cubeFace1[i][0]=cubeFace1[i][n + 1]=cubeFace1[0][i]=cubeFace1[n+1][i]=-1;
        cubeFace2[i][0]=cubeFace2[i][n + 1]=cubeFace2[0][i]=cubeFace2[n+1][i]=-1;
    }
    if(cer==1) {
        coverCubeFirstReq();
        return 0;
    }
    coverCubeSecondReq();
    return 0;
}