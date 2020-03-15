#include <iostream>
#include <vector>
using namespace std;
class Point {
public:
    int x,y;
    Point () {
        x=0;
        y=0;
    }
};
int sign (Point p1, Point p2, Point p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}


class Triangle {
public:
    Point v1,v2,v3;
    bool includesPoint(Point pt) {
        int d1, d2, d3;
        bool has_neg, has_pos;

        d1 = sign(pt, v1, v2);
        d2 = sign(pt, v2, v3);
        d3 = sign(pt, v3, v1);

        has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
        has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

        return !(has_neg && has_pos);
    }
};
Triangle fields[70];
vector<int>wateredFields;
int main() {
    freopen("triunghi2.in","r",stdin);
    freopen("triunghi2.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d%d%d%d%d%d",&fields[i].v1.x ,&fields[i].v1.y ,&fields[i].v2.x ,&fields[i].v2.y ,&fields[i].v3.x ,&fields[i].v3.y);
    }
    Point waterBank;
    scanf("%d%d",&waterBank.x,&waterBank.y);
    int numberOfWateredFields=0;
    for(int i=1;i<=n;++i) {
        if(fields[i].includesPoint(waterBank)) {
            numberOfWateredFields++;
            wateredFields.emplace_back(i);
        }
    }
    printf("%d ",numberOfWateredFields);
    for (int i:wateredFields) {
        printf("%d ",i);
    }
    printf("\n");
    for(int i=1;i<=n;++i) {
        int containedFields=0;
        for(int j=1;j<=n;++j) {
            if(fields[i].includesPoint(fields[j].v1) && fields[i].includesPoint(fields[j].v2) &&  fields[i].includesPoint(fields[j].v3)) {
                containedFields++;
            }
        }
        if(containedFields==n) {
            printf("%d\n",i);
            return 0;
        }
    }

    printf("0\n");
    return 0;
}
