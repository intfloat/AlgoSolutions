//自己简直弱爆了啊……惭愧 
#include<iostream>
using namespace std;
int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
int main(){
	int total,n,t,m,Arrival[1500],time[1500],trip[1500];
	cin>>total;
	while(total--){
		cin>>n>>t>>m;
		time[0]=0; trip[0]=0;
		for(int i=1;i<=m;i++){
			cin>>Arrival[i];		
		}
		for(int i=1;i<=m;i++){
			time[i]=max(time[max(i-n,0)],Arrival[i])+2*t;
			trip[i]=trip[max(i-n,0)]+1;
		}
		cout<<time[m]-t<<" "<<trip[m]<<endl;
	}
	system("pause");
	return 0;
}
