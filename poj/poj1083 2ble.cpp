#include<iostream>
using namespace std;
int main(){
	int t,n,room[405],tmpx,tmpy,maximum;	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<405;i++){
			room[i]=0;
		}
		for(int i=0;i<n;i++){
			cin>>tmpx>>tmpy;
			if(tmpx%2==1)
				tmpx++;
			if(tmpy%2==1)
				tmpy++;
			if(tmpx<tmpy){
				for(int i=tmpx;i<=tmpy;i++)
					room[i]++;
			}
			else{
				for(int i=tmpy;i<=tmpx;i++)
					room[i]++;
			}
		}
		maximum=0;
		for(int i=0;i<405;i++){
			if(room[i]>maximum)
				maximum=room[i];
		}
		cout<<maximum*10<<endl;
	}
	return 0;
}
