#include<iostream>
using namespace std;
int main(){
	int n,goal_x,goal_y;
	int x[10005],y[10005],xwid[10005],ywid[10005];
	bool flag;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i]>>xwid[i]>>ywid[i];
	cin>>goal_x>>goal_y;
	flag=false;
	for(int i=n-1;i>=0;i--){
		if(goal_x>=x[i]&&goal_x<=x[i]+xwid[i]&&goal_y>=y[i]&&goal_y<=y[i]+ywid[i]){
			flag=true;
			cout<<i+1<<endl;
			break;
		}
	}
	if(flag==false)
		cout<<-1<<endl;
	system("pause");
	return 0;
}
