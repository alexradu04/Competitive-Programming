#include <cstdio>
#include <algorithm>

using namespace std;
int numbers[5005];
int leftMax[5005];
int leftMin[5005];
int rightMin[5005];
int rightMax[5005];
int n;
int maxSum;
int finalLeftIndex;
int finalRightIndex;

int finalMiddleIndex;

void updateMax (int middle) {
    int leftIndex=0,rightIndex=0;
    int currMax=-1;
    int currMin=1e9;
    int maxLeft=0,maxRight=0;
    for(int i=middle;i>2;--i) {
        currMax=max(currMax,numbers[i]);
        currMin=min(currMin,numbers[i]);
        if(maxLeft<= currMax - currMin + leftMax[i-1]-leftMin[i-1] ) {
            maxLeft = currMax - currMin + leftMax[i-1]-leftMin[i-1];
            leftIndex=i-1;
        }
    }
    currMax=-1;
    currMin=1e9;
    for(int i=middle+1;i<n-1;++i) {
        currMax=max(currMax,numbers[i]);
        currMin=min(currMin,numbers[i]);
        if(maxRight< currMax - currMin + rightMax[i+1]-rightMin[i+1] ) {
            maxRight = currMax - currMin + rightMax[i+1]-rightMin[i+1];
            rightIndex=i;
        }
    }
    if(maxSum < maxLeft + maxRight) {
        maxSum= maxLeft +maxRight;
        finalLeftIndex=leftIndex;
        finalMiddleIndex=middle;
        finalRightIndex=rightIndex;
    }
}
int main() {
    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d",&numbers[i]);
    }
    leftMax[0]=-1;
    leftMin[0]=1e9;
    for(int i=1;i<=n;++i) {
        leftMax[i]=max(numbers[i],leftMax[i-1]);
        leftMin[i]=min(numbers[i],leftMin[i-1]);
    }
    rightMax[n+1]=-1;
    rightMin[n+1]=1e9;
    for(int i=n;i>=1;--i) {
        rightMax[i]=max(numbers[i],rightMax[i+1]);
        rightMin[i]=min(numbers[i],rightMin[i+1]);
    }
    for(int i=4;i<n-1;++i) {
        updateMax(i);
    }
    printf("%d\n",maxSum)  ;
    printf("%d %d %d\n",finalLeftIndex, finalMiddleIndex, finalRightIndex);
    return 0;
}
