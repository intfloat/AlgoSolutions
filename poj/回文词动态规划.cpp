#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int search(int begin,int end);
//int dp[3005][3005];
char str[5005];	
int main(){
	int len;	
	cin>>len;
	cin>>str;
	//for(int i=0;i<len;i++)
	//for(int j=0;j<len;j++)
	//	dp[i][j]=-1;	
	cout<<search(0,len-1)<<endl;
	//cout<<dp[0][len-1]<<endl;
	system("pause");
	return 0;
}

int search(int begin,int end){
	if(begin>=end){
		//dp[begin][end]=0;
		return 0;
	}
	//if(dp[begin][end]!=-1)
	//	return dp[begin][end];
	if(str[begin]==str[end])
		return search(begin+1,end-1);
	else 
		return min(search(begin,end-1)+1,search(begin+1,end)+1);
	//return dp[begin][end];
}
