#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	int res=0;
	string colors;
	
	cin>>n>>colors;
	for(int i=1;i<n;i++){
		if(colors[i]==colors[i-1])
			res++;
	}
	cout<<res<<endl;
	return 0;
}
