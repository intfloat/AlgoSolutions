#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,res,pos;
	int h[100005];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>h[i];
	
	res=0; pos=0;
	res+=n;
	res+=n-1;
	
	for(int i=0;i<n;i++){
		res+=abs(h[i]-pos);
		pos=h[i];
	}
	cout<<res<<endl;
	return 0;
}
