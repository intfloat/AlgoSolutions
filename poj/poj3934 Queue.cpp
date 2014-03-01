#include<iostream>
using namespace std;
int main(){
	int n,m,dp[85][1005];
	for(int i=0;i<85;i++)
	for(int j=0;j<1005;j++)
		dp[i][j]=0;
	dp[2][1]=2; 
	dp[1][0]=1;
	for(int i=3;i<=80;i++)
	for(int j=0;j<=1000;j++){
		if(j>=2)
			dp[i][j]=(dp[i-1][j-2]*(i-2))%9937;
		if(j>=1)
			dp[i][j]=(dp[i][j]+dp[i-1][j-1]*2)%9937;
		
	}
	while(cin>>n>>m){
		if(n==0&&m==0)
			break;
		cout<<dp[n][m]<<endl;
	}
	system("pause");
	return 0;
}
