/**
Ion Alexandru Radu
Grade 9
Cygnus Computer Bucharest-Romania
Intermediate 5 Division
Contest #4
Language:c++
**/
#include <cstdio>
#include <map>
using namespace std;
map<int,int> occupiedPositions;
map<int,int>primes;
map<int,int>squares;
map<int,int>rule9Map;


bool CheckRule9(int &position, map<int, int> mapmap, int startPos, int numberRolled) {
    int ok=0;
    for(int i=1;i<=52;++i) {
        if(rule9Map[i] && mapmap[i] && mapmap[i-1] && mapmap[i+1])
            ok=1;
    }
    if(ok) {
        bool didBreak=false;
        int currentMarkerPos=position;
        for(;currentMarkerPos>=0&&currentMarkerPos>=startPos;--currentMarkerPos) {
            if(!occupiedPositions[currentMarkerPos] && currentMarkerPos%numberRolled == 0) {
                didBreak=true;
                break;
            }
        }
        position = !didBreak ? currentMarkerPos + 1 : currentMarkerPos;
        return true;
    } else {
        return false;
    }
}

bool checkSquareCase(int &position) {
    if(squares[position]) {
        int currentMarkerPos=position;
        for(;currentMarkerPos>=0&&currentMarkerPos-position>=-6;--currentMarkerPos) {
            if(occupiedPositions[currentMarkerPos]) {
                break;
            }
        }
        position=currentMarkerPos+1;
        return true;
    }
    return false;
}

bool checkPrimeCase(int &position) {
    if(primes[position]) {
        int currentMarkerPos=position;
        for(;currentMarkerPos<=52&&currentMarkerPos-position<=6;++currentMarkerPos) {
            if(occupiedPositions[currentMarkerPos]) {
                break;
            }
        }
        position=currentMarkerPos-1;
        return true;
    }
    return false;
}

void simulateMove(int diceRoll) {
    int markerPosition=0;
    map<int,int>passed;
    for(int i=1;i<=52;++i) {
        if(occupiedPositions[i]==1) {
            markerPosition = i;
            break;
        }

    }
    int startRoll=markerPosition;
    int player=occupiedPositions[markerPosition];
    int currentMarkerPos=markerPosition;
    for(;currentMarkerPos<=52&&currentMarkerPos-markerPosition<=diceRoll;++currentMarkerPos) {
        passed[currentMarkerPos]++;
    }
    currentMarkerPos--;
    markerPosition=currentMarkerPos;
    if(occupiedPositions[markerPosition])
        return;
    occupiedPositions[startRoll]= 0;
    if(!checkPrimeCase(markerPosition) && !checkSquareCase(markerPosition)) {
        CheckRule9(markerPosition, passed,startRoll, diceRoll);
    }
    occupiedPositions[markerPosition]=player;

}
void initialiseData(int p1, int p2, int p3, int op1, int op2, int op3);

int main() {

    for(int index=1;index<=5;++index) {
        occupiedPositions.clear();
        int diceRolls;
        int p1,p2,p3,op1,op2,op3;
        scanf("%d%d%d%d%d%d%d",&op1,&op2,&op3,&p1,&p2,&p3,&diceRolls);
        initialiseData(p1, p2, p3, op1, op2, op3);
        int roll;
        for(int i=1;i<=diceRolls;++i) {
            scanf("%d",&roll);
            simulateMove(roll);
        }
        for(int i=1;i<=51;++i) {
            if(occupiedPositions[i]==1) {
                printf("%d ",i);
            }
        }
        printf("\n");
    }
    return 0;
}

void initialiseData(int p1, int p2, int p3, int op1, int op2, int op3) {

    occupiedPositions[op1]=2;
    occupiedPositions[op2]=2;
    occupiedPositions[op3]=2;
    occupiedPositions[p1]=1;
    occupiedPositions[p2]=1;
    occupiedPositions[p3]=1;
    primes[2] = 1 ;
    primes[3] = 1 ;
    primes[5] = 1 ;
    primes[7] = 1 ;
    primes[11] = 1 ;
    primes[13] = 1 ;
    primes[17] = 1 ;
    primes[19] = 1 ;
    primes[23] = 1 ;
    primes[29] = 1 ;
    primes[31] = 1 ;
    primes[37] = 1 ;
    primes[41] = 1 ;
    primes[43] = 1 ;
    primes[47] = 1 ;
    squares[9] = 1 ;
    squares[16] = 1 ;
    squares[25] = 1 ;
    squares[36] = 1 ;
    squares[49] = 1;
    rule9Map[7] = 1;
    rule9Map[12] = 1;
    rule9Map[17] = 1;
    rule9Map[22] = 1;
    rule9Map[27] = 1;
    rule9Map[35] = 1;
    rule9Map[40] = 1;
    rule9Map[45] = 1;
    rule9Map[50] = 1;
}
