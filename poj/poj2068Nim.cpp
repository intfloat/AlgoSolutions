#include<iostream>
using namespace std;
int search(int count,int leftNumber);
int n,maxNumber[50];
int dp[25][10001];
int main(){
	int total;
	while(cin>>n&&n){
		cin>>total;
		n=n*2;
		for(int i=0;i<n;i++)
			cin>>maxNumber[i];
		for(int i=0;i<n;i++)
		for(int j=0;j<=total;j++)
			dp[i][j]=-1;	//the process of initialization
		search(0,total);
		cout<<dp[0][total]<<endl;
	}
	system("pause");
	return 0;
}

int search(int count,int leftNumber){
	if(dp[count][leftNumber]!=-1)
		return dp[count][leftNumber];
	//boundary conditions
	if(leftNumber==0){
		dp[count][leftNumber]=1;
		return 1;
	}
	else if(leftNumber==1){
		dp[count][leftNumber]=0;
		return 0;
	}
	for(int i=1;i<=maxNumber[count];i++){
		if((leftNumber-i)>=0&&search((count+1)%n,leftNumber-i)==0){
			dp[count][leftNumber]=1;
			return 1;
		}
	}
	dp[count][leftNumber]=0;
	return 0;
}
