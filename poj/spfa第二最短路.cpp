//囧啊囧，贴在cadn上的居然是错误的 
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct Road{
	int x,y,wei;
	bool operator<(const Road& r)const{
		if(x==r.x){
			if(y==r.y) 	return wei<r.wei;
			return y<r.y;
		}
		return x<r.x;
	}
};
Road road[200005];
queue<int> q;
int n,m,pos[5005],dis1_n[5005],disn_1[5005],dis[5005];

void spfa(int begin);
int main(){
	int minRoad,result;
	scanf("%d%d",&n,&m);	
	for(int i=0;i<=n;i++)
		pos[i]=0;
	for(int i=0;i<2*m;i++){
		scanf("%d%d%d",&road[i].x,&road[i].y,&road[i].wei);		
		i++;
		road[i].x=road[i-1].y;
		road[i].y=road[i-1].x;
		road[i].wei=road[i-1].wei;
		pos[road[i].x]++;
		pos[road[i].y]++;
	}
	for(int i=2;i<=n;i++)
		pos[i]+=pos[i-1];
	sort(road,road+2*m);
	spfa(1);
	for(int i=1;i<=n;i++)
		dis1_n[i]=dis[i];
	spfa(n);
	for(int i=1;i<=n;i++)
		disn_1[i]=dis[i];
	minRoad=disn_1[1];
	//cout<<"minRoad: "<<minRoad<<endl;
	result=999999;
	for(int i=0;i<2*m;i++){
		result=min(result,minRoad+2*road[i].wei);
		if(dis1_n[road[i].x]+disn_1[road[i].y]+road[i].wei<=minRoad)
			continue;
		result=min(result,dis1_n[road[i].x]+disn_1[road[i].y]+road[i].wei);
	}	
	cout<<result<<endl;
	system("pause");
	return 0;
}

void spfa(int begin){
	int t;
	while(q.empty()==false)
		q.pop();
	for(int i=1;i<=n;i++){
		dis[i]=999999;		
	}
	q.push(begin);
	dis[begin]=0;
	while(q.empty()==false){
		int tmp=q.front();
		q.pop();
		for(int i=pos[tmp]-1;road[i].x==tmp;i--){
			//cout<<"haha"<<endl;
			t=road[i].y;			
			if(dis[tmp]+road[i].wei<dis[t]){
				dis[t]=dis[tmp]+road[i].wei;
				q.push(t);
			}
		}
	}
	return;
}
