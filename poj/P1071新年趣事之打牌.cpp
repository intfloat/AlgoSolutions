#include<iostream>
#include<stack> 
#include<string.h>
#include<algorithm>
#define SIZE 100005
using namespace std;

int main(){
	int totalW,sum;
	int n,wei[105];
	int dp[SIZE],path[SIZE];
	
	memset(dp,0,sizeof(dp));
	memset(path,0,sizeof(path));
	
	cin>>totalW>>n;
	sum=0;	
	for(int i=0;i<n;i++){
		cin>>wei[i];
		sum+=wei[i];
	}
	int left=sum-totalW;
	
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=left;j>=wei[i];j--){
			//该条语句非常关键 
			if((dp[j]==0) && (dp[j-wei[i]]>0))
				path[j]=i+1;
			dp[j]+=dp[j-wei[i]];
			
		}
	}
	
	if(dp[left]==0)
		cout<<0<<endl;
	else if(dp[left]>1)
		cout<<-1<<endl;
	else if(dp[left]==1){
		stack<int> s;		
		while(s.empty()==false)
			s.pop();
		while(path[left]!=0){
			s.push(path[left]);
			left=left-wei[path[left]-1];
		}
		while(s.size()>1){
			int tmp=s.top();
			cout<<tmp<<" ";
			s.pop();
		}
		cout<<s.top();
		cout<<endl;
	}
	//system("pause");
	return 0;
}
