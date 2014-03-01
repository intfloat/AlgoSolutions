/*
以空格作为石子数目，可以将石子放到右边的相邻位置
也可以将最右边的石子扔掉。
偶数位置的石子相当于被扔掉，对于结局的胜败毫无作用。 
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t,n,sum,position[10005];
	cin>>t;
	while(t--){
		cin>>n;
		position[0]=0;
		for(int i=1;i<=n;i++)
			cin>>position[i];
		sort(position,position+n+1);
		sum=0;
		for(int i=n;i>0;i-=2){
			sum=sum^(position[i]-position[i-1]-1);
		}
		if(sum==0)
			cout<<"Bob will win"<<endl;
		else cout<<"Georgia will win"<<endl;
	}
	system("pause");
	return 0;
} 
