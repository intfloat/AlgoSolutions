#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
 
using namespace std;
 
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int n,k;
	int cor[100];
	
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>cor[i];
	sort(cor,cor+n);
	if(k>n || k<0)
		cout<<-1<<endl;
	else if(k==0)
		cout<<cor[n-1]+1<<" "<<cor[n-1]+1<<endl;
	else
		cout<<cor[n-k]<<" "<<cor[n-k]<<endl;
	return 0;
}

