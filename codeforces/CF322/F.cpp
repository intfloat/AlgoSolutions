// by fwm94
#include <bits/stdc++.h>
#define maxn 5009
using namespace std;
int n,root,cnt;
int du[maxn],sz[maxn];
vector<int>G[maxn];
int dp[maxn][maxn][2];
void dfs(int u,int fa)
{
    sz[u]=0;
    if((int)G[u].size()==1)
    {
        dp[u][0][0]=0;
        dp[u][1][1]=0;
        sz[u]=1;
        return;
    }
    dp[u][0][0]=dp[u][0][1]=0;
    int sum=0;
    for(int i=0;i<(int)G[u].size();i++)
    {
        int v=G[u][i];
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        sum+=sz[v];
        for(int j=min(cnt/2,sum);j>=0;j--)
        {
            dp[u][j][0]+=min(dp[v][0][0],dp[v][0][1]+1);
            dp[u][j][1]+=min(dp[v][0][1],dp[v][0][0]+1);
            for(int k=1;k<=sz[v]&&k<=j;k++)
            {
                dp[u][j][0]=min(dp[u][j][0],dp[u][j-k][0]+dp[v][k][0]);
                dp[u][j][0]=min(dp[u][j][0],dp[u][j-k][0]+dp[v][k][1]+1);
                dp[u][j][1]=min(dp[u][j][1],dp[u][j-k][1]+dp[v][k][1]);
                dp[u][j][1]=min(dp[u][j][1],dp[u][j-k][1]+dp[v][k][0]+1);
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
        du[x]++;du[y]++;
    }
    if(n==2)
    {
        puts("1");
        return 0;
    }
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(du[i]>=2)
            root=i;
        if(du[i]==1)
            cnt++;
    }
    memset(dp,0x3f,sizeof(dp));
    dfs(root,-1);
    printf("%d\n",min(dp[root][cnt/2][0],dp[root][cnt/2][1]));
    return 0;
}
