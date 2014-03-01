#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> v[20005];
int n,maximum,boss,record[20005][2];
char str[20005][105],str_boss[20005][105];
bool notUnique[20005][2];

int dp(int node, bool selected);
bool notUniqueFun(int node,bool selected);
int getBoss(int number);


int main(){
	while(scanf("%d",&n)&&n){	
		for(int i=0;i<n;i++){
			v[i].clear();
			record[i][0]=-1;		
			record[i][1]=-1;
			notUnique[i][0]=false;
			notUnique[i][1]=false;
		}
		scanf("%s",str[0]);
		for(int i=1;i<n;i++)
			scanf("%s%s",str[i],str_boss[i]);
	
		for(int i=1;i<n;i++){			
			boss=getBoss(i);
			v[boss].push_back(i);
		}
		
		//get the result
		maximum=max(dp(0,true),dp(0,false));
		cout<<maximum<<" ";
		if(dp(0,true)>dp(0,false)&&notUniqueFun(0,true)==true)
			cout<<"No"<<endl;		
		else if(dp(0,true)>dp(0,false)&&notUniqueFun(0,true)==false)
			cout<<"Yes"<<endl;
		else if(dp(0,true)==dp(0,false))
			cout<<"No"<<endl;			
		else if(dp(0,true)<dp(0,false)&&notUniqueFun(0,false)==true)
			cout<<"No"<<endl;		
		else cout<<"Yes"<<endl;
		
	}

	return 0;
} 

bool notUniqueFun(int node,bool selected){
	
	if(selected==false&&notUnique[node][0]==true)
		return true;
	if(selected==true&&notUnique[node][1]==true)
		return true;
	int len=v[node].size();
	
	if(selected==true){
		for(int i=0;i<len;i++){
			if(notUniqueFun(v[node][i],false)==true){
				notUnique[node][1]=true;
				return true;
			}
		}
	}
	else if(selected==false){
		for(int i=0;i<len;i++){
			int number1=record[v[node][i]][1],number2=record[v[node][i]][0];
			if(number1==number2){
				notUnique[node][0]=true;
				return true;
			}
			else if(number1>number2&&notUniqueFun(v[node][i],true)==true){
				notUnique[node][0]=true;
				return true;
			}
			else if(number2>number1&&notUniqueFun(v[node][i],false)==true){
				notUnique[node][0]=true;
				return true;
			}//end if
		}//end for loop
	}//end else if
	return false;
}

//¼ÇÒä»¯ËÑË÷ 
int dp(int node,bool selected){
	
	if(selected==false&&record[node][0]!=-1)
		return record[node][0];
	else if(selected==true&&record[node][1]!=-1)
		return record[node][1];
	
	int sum=0;
	int len=v[node].size();
	if(selected==true){		
		for(int i=0;i<len;i++)
			sum+=dp(v[node][i],!selected);		
	}
	else if(selected==false){
		for(int i=0;i<len;i++){
			sum+=max(dp(v[node][i],true),dp(v[node][i],false));
		}
	}
	if(selected==false){
		record[node][0]=sum;
		return sum;
	}
	else{
		record[node][1]=sum+1;
		return sum+1;
	}
	
}


int getBoss(int number){
	for(int i=0;i<n;i++){
		if(strcmp(str[i],str_boss[number])==0)
			return i;
	}
	return 0;
}
