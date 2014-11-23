#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
void build();
bool check(int i,int j);

vector<int> factor[100005];
int n,number[100005];
int res[100005];
int maxi=-1;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	memset(res,0,sizeof(res));
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>number[i];
	build();
	for(int i=0;i<n;i++){
		res[i]=1;
		for(int j=i-1;j>=0;j--){
			if(res[j]+1 <= res[i])
				continue;
			if(check(j,i)==true)
				res[i]=res[j]+1;
		}
		maxi=max(maxi,res[i]);
	}
	cout<<maxi<<endl;
	return 0;
}

void build(){
	for(int i=0;i<n;i++){
		int tmp=(int)sqrt(number[i]);
		for(int j=2;j<=tmp;j++){
			if(number[i]%j==0){
				factor[i].push_back(j);
				factor[i].push_back(number[i]/j);
			}
		}
	}
	return;
}

bool check(int i,int j){
	int num1=number[i],num2=number[j];
	if(num1==1)
		return false;
	if(num2%num1==0)
		return true;
	int len=factor[i].size();
	for(int k=0;k<len;k++){
		if(num2%factor[i][k]==0)
			return true;
	}
	return false;
}
