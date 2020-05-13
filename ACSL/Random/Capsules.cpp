#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int n,m, completedSquares;
enum Position{
    Top=0,
    Right=1,
    Bottom=2,
    Left=3,
};
class Square {
public:
    int x,y,val,island;
    map<int,bool>walls;
    Position _where(Square lilSquare) {
        if(lilSquare.y>y)
            return Right;
        if(lilSquare.y<y) {
            return Left;
        }
        if(lilSquare.x<x) {
            return Top;
        }
        if(lilSquare.x>x) {
            return Bottom;
        }
    }
    bool canReach(Square lilSquare) {
        int pos=this->_where(lilSquare);
        if(pos==Right) {
            if(this->walls[Right] || lilSquare.walls[Left])
                return false;
            return true;
        }
        if(pos==Top) {
            if(this->walls[Top] || lilSquare.walls[Bottom])
                return false;
            return true;
        }
        if(pos==Left) {
            if(this->walls[Left] || lilSquare.walls[Right])
                return false;
            return true;
        }
        if(pos==Bottom) {
            if(this->walls[Bottom] || lilSquare.walls[Top])
                return false;
            return true;
        }
    }
};
Square mat[20][20];
int hexTo10(char hexVall)
{
    char hexVal[2];
    hexVal[0]=hexVall;
    hexVal[1]=NULL;
    int len = strlen(hexVal);
    int base = 1;
    int dec_val = 0;
    for (int i=len-1; i>=0; i--)
    {
        if (hexVal[i]>='0' && hexVal[i]<='9')
        {
            dec_val += (hexVal[i] - 48)*base;
            base = base * 16;
        }
        else if (hexVal[i]>='A' && hexVal[i]<='F')
        {
            dec_val += (hexVal[i] - 55)*base;
            base = base*16;
        }
    }
    return dec_val;
}
void complete(int x,int y,int borders) {
    mat[x][y].x=x;
    mat[x][y].y=y;
    if(borders&1) {
        mat[x][y].walls[Left]= true;
    }
    borders>>=1;
    if(borders&1) {
        mat[x][y].walls[Bottom]= true;
    }
    borders>>=1;
    if(borders&1) {
        mat[x][y].walls[Right]= true;
    }
    borders>>=1;
    if(borders&1) {
        mat[x][y].walls[Top]= true;
    }
}
void next_coord(int &x, int &y) {
    y++;
    if(y>m) {
        y=1;
        x--;
    }
}
pair<int,int>bkt_next_coord(int _x,int _y) {
    int y=_y;
    int x=_x;
    y++;
    if(y>m) {
        y=1;
        x++;
    }
    return make_pair(x,y);
}
bool viz[20][20];
map<int,int>howManySquares;
int noOfIslands=0;
bool ok=false;
bool ok2=false;
void dfs (int x,int y) {
    if(viz[x][y] || x>n || y>m || x<1 || y<1)
        return;
    else {
        if(!ok) {
            ok=1;
            noOfIslands++;
        }
        mat[x][y].island=noOfIslands;
        howManySquares[noOfIslands]++;
        viz[x][y]=1;
    }
    if(mat[x][y].val!=0)
        ok2= true;
    if(mat[x][y].canReach(mat[x+1][y]))
        dfs(x+1,y);
    if(mat[x][y].canReach(mat[x-1][y]))
        dfs(x-1,y);
    if(mat[x][y].canReach(mat[x][y+1]))
        dfs(x,y+1);
    if(mat[x][y].canReach(mat[x][y-1]))
        dfs(x,y-1);
}
map<pair<int,int>,int>freqIsland;
bool verif() {
    map<pair<int,int>,int>freq;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            freq[make_pair(mat[i][j].island,mat[i][j].val)]++;
            if(freq[make_pair(mat[i][j].island,mat[i][j].val)]>=2) {
                return false;
            }
            if(mat[i][j].val==mat[i+1][j].val || mat[i][j].val==mat[i][j+1].val || mat[i][j].val==mat[i+1][j+1].val) {
                return false;
            }
        }
    }
    return true;
}
bool low_verif() {
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if((mat[i][j].val!=0 && mat[i+1][j].val!=0 && mat[i][j].val==mat[i+1][j].val) ||
               (mat[i][j].val!=0 && mat[i][j+1].val!=0 && mat[i][j].val==mat[i][j+1].val) ||
               (mat[i][j].val!=0 && mat[i+1][j+1].val!=0 && mat[i][j].val==mat[i+1][j+1].val) ||
               (mat[i][j].val!=0 && mat[i+1][j-1].val!=0 && mat[i][j].val==mat[i+1][j-1].val)) {
                return false;
            }
        }
    }
    return true;
}
void bkt (int x, int y) {
    if(ok==1)
        return;
    if(x==n+1)
    {
        if(verif()) {
            ok=1;
            return;
        }
    }
    if(!low_verif())
        return;
    if(mat[x][y].val!=0) {
        bkt(bkt_next_coord(x,y).first,bkt_next_coord(x,y).second);
    }
    for(int i=1;i<=howManySquares[mat[x][y].island];++i) {
        //if(mat[x][y].val!=0)
        //  freqIsland[make_pair(mat[x][y].island,mat[x][y].val)]++;
        if(mat[x][y].val!=0 || i==mat[x-1][y].val || i==mat[x][y-1].val)
            continue;
        mat[x][y].val=i;
        //freqIsland[make_pair(mat[x][y].island,mat[x][y].val)]++;
        bkt(bkt_next_coord(x,y).first,bkt_next_coord(x,y).second);
        //freqIsland[make_pair(mat[x][y].island,mat[x][y].val)]--;
        if(ok==1)
            return;
        mat[x][y].val=0;
    }
}
int main() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    string s;
    cin>>n>>m;
    cin>>s;
    cin>>completedSquares;
    int coordx=n,coordy=1;
    for(int i=1;i<=completedSquares;++i) {
        int x;
        cin>>x;
        mat[n-x/100+1][(x/10)%10].val=x%10;
    }
    for(int i=0;i<s.size();++i) {
        int borders=hexTo10(s[i]);
        complete(coordx,coordy,borders);
        next_coord(coordx,coordy);
    }
    int cleanIntersect=0;
    for(int i=1;i<n;++i) {
        for(int j=1;j<m;++j) {
            if(mat[i][j].canReach(mat[i+1][j]) && mat[i][j].canReach(mat[i][j+1])
               && mat[i+1][j].canReach(mat[i+1][j+1]) && mat[i][j+1].canReach(mat[i+1][j+1])) {
                cleanIntersect++;
            }
        }
    }
    printf("%d\n",cleanIntersect);
    int helpedIslands=0;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            ok=0;
            dfs(i,j);

        }
    }
    printf("%d\n",noOfIslands);
    helpedIslands=noOfIslands;
    map<int,bool>markedIslands;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(mat[i][j].val!=0) {
                if(!markedIslands[mat[i][j].island]) {
                    markedIslands[mat[i][j].island]=1;
                    helpedIslands--;
                }
            }
        }
    }
    printf("%d\n",helpedIslands);
    for(int i=0;i<=n;++i) {for(int j=0;j<=m;++j) viz[i][j]=0;}
    ok=0;
    bkt(1,1);
    //for(int i=1;i<=5;++i) {
    //    printf("%d ",howManySquares[i]);
    //}
    //printf("\n\n");

    int sum1=0;
    int sum2=0;
    for(int i=1;i<=max(n,m);++i) {
        sum1+=mat[1][i].val;
        sum2+=mat[i][1].val;
    }
    printf("%d\n%d",sum1,sum2);
    return 0;
}
