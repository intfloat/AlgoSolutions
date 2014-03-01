#include<iostream>
using namespace std;
int main(){
	int t,m,number,goal[10005],s[105],tmp,mark[10005];
	while(cin>>t&&t){
		for(int i=0;i<t;i++)
			cin>>s[i];
		goal[0]=0;
		for(int i=0;i<10005;i++)
			mark[i]=9999999;
		for(int i=1;i<=10000;i++){			
			for(int j=0;j<t;j++){
				if(i>=s[j]){
					mark[goal[i-s[j]]]=i;
				}
			}
			goal[i]=0;
			while(mark[goal[i]]==i)
				goal[i]++;
		}
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>number;
			int sum=0;
			for(int j=0;j<number;j++){
				cin>>tmp;				
				sum=sum^goal[tmp];
			}
			if(sum==0)
				cout<<"L";
			else cout<<"W";
		}
		cout<<endl;
	}
	
	return 0;
}
