#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct bian{
    int next,point;
}b[210000];
int p[110000],n,dp[110000][3],len,father[110000];
void ade(int k1,int k2){
    b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
    ade(k1,k2); ade(k2,k1);
}
void treedp(int k1,int k2){
    for (int i=p[k1];i;i=b[i].next){
        int j=b[i].point;
        if (j!=k2){
            treedp(j,k1); dp[k1][0]+=dp[j][1];
        }
    }
    dp[k1][0]++;
    for (int i=p[k1];i;i=b[i].next){
        int j=b[i].point;
        if (j!=k2){
            int pre=dp[k1][1];
            dp[k1][1]=min(dp[k1][1]+dp[j][0],min(dp[k1][1],dp[k1][2])+dp[j][2]+1);
            dp[k1][2]=min(dp[k1][2]+dp[j][0],pre+dp[j][2]);
        }
    }
    dp[k1][2]=min(dp[k1][2],dp[k1][1]);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
    }
    treedp(1,0);
    printf("%d\n",min(dp[1][0],dp[1][1]));
    return 0;
}
