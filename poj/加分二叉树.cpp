//动态规划+前序遍历节点
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
int flag=0,root[31][31],n;
void out(int a,int b);
int main()
{
    int i,j,k,head,_max,dp[31][31];
    scanf("%d",&n);
    for (i=0;i<n+2;i++)
    {
        for (j=0;j<n+2;j++)
        {
            dp[i][j]=1;
        }
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&dp[i][i]);
    }
    for (i=1;i<n;i++)//i为间隔
    {
        for (j=1;j<n-i+1;j++)
        {
            _max=0;
            for (k=j;k<=i+j;k++)//找根节点k  左子树i
            {
                if(_max<dp[j][k-1]*dp[k+1][j+i]+dp[k][k])
                {
                    _max=dp[j][k-1]*dp[k+1][j+i]+dp[k][k];
                    root[j][j+i]=k;
                }
            }
            dp[j][j+i]=_max;
        }
    }
    printf("%d\n",dp[1][n]);
    out(1,n);
    system("pause");
}
void out(int a,int b)
{ 
    if(a>b) return; 
    if(a==b){ 
        flag++;
        if (flag==n)
        {
         printf("%d\n",a);
        }
        else printf("%d ",a); 
        return;        
    } 
    flag++;
    if (flag==n)
    {
     printf("%d\n",root[a][b]);
    }
    else 
        printf("%d ",root[a][b]);
    out(a,root[a][b]-1); 
    out(root[a][b]+1,b); 
}
