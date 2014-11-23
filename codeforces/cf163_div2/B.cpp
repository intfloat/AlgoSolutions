#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out1.txt","w",stdout);
	int n,t;
	string res,tmp;
	
	cin>>n>>t;
	cin>>tmp;
	res=tmp;
	for(int i=0;i<t;i++){
		for(int j=0;j<n;j++){
			if(tmp[j]=='B' && tmp[j+1]=='G' && j!=n-1){
				res[j]='G';
				res[j+1]='B';
				j++;
			}
			else
				res[j]=tmp[j];
		}
		tmp=res;
	}	
	cout<<res<<endl;
	system("pause");
	return 0;
}
