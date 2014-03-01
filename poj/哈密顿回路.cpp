#include<iostream>
#include<queue>
using namespace std;
int path[270000][18];
bool check[270000];
queue<int> q;
int main(){
	int m,minimum,n;
	int dis[20][20];
	cin>>n;
	int number=1;
	for(int i=0;i<n-1;i++)
		number*=2;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		cin>>dis[i][j];
	for(int i=0;i<number;i++){
		check[i]=false;
		for(int j=1;j<n;j++){
			path[i][j]=9999999;
		}
	}
	while(q.empty()==false)
		q.pop();
	
	for(int i=0;i<n-1;i++){
		path[(1<<i)][i+1]=dis[0][i+1];
		q.push((1<<i));
		check[(1<<i)]=true;
	}
	while(q.empty()==false){
		int tmp=q.front();
		q.pop();
		for(int i=1;i<n;i++){			
			if(path[tmp][i]>=999999)
				continue;
			//cout<<"tmp: "<<tmp<<" i: "<<i<<" distance: "<<path[tmp][i]<<endl;
			for(int j=0;j<n-1;j++){
				if(((tmp&(1<<j))>>j)==1)
					continue;
				int tm=tmp|(1<<j);
				if(path[tm][j+1]>path[tmp][i]+dis[i][j+1])
					path[tm][j+1]=path[tmp][i]+dis[i][j+1];
				if(check[tm]==false){
					check[tm]=true;
					q.push(tm);
				}
			}
		}	
		//cout<<endl;	
	}
	minimum=9999999;
	for(int i=1;i<n;i++){
		if(path[number-1][i]+dis[i][0]<minimum)
			minimum=path[number-1][i]+dis[i][0];
	}
	cout<<minimum<<endl;
	system("pause");
	return 0;
} 
