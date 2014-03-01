#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int nMax=10000;
int num[nMax];
int dp[nMax];
int tim[nMax];
int main(){
    int n,i,j,k;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        for(i=1;i<=n;i++){
            dp[i]=1;
            tim[i]=1;
        }
        for(i=1;i<=n;i++){
            for(j=i-1;j>=1;j--){
                if(num[j]>num[i]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        tim[i]=tim[j];
                    }
                    else{
                        if(dp[j]+1==dp[i]){
                            tim[i]+=tim[j];
                        }
                    }
                }
                else{
                    if(num[i]==num[j]){
                        if(dp[i]==1){
                            tim[i]=0;
                        }
                        break;
                    }
                }
            }
        }
        for(int k=1;k<=n;k++)
        	cout<<k<<" "<<tim[k]<<endl; 
        int ans1=-1,ans2=0;
        for(i=1;i<=n;i++){
            if(dp[i]>ans1){
                ans1=dp[i];
            }
        }
        for(i=1;i<=n;i++){
            if(dp[i]==ans1){
                ans2+=tim[i];
            }
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
    system("pause"); 
    return 0;
}
