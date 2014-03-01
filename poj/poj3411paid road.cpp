#include<iostream>
#include<algorithm>
using namespace std;

struct Road{
	int a,b,c,p,r;
};
Road road[15];
const int MAX=999999;
void dfs(int node,int currentCost);

int n,m,minimum,sum;
int visited[15];

int main(){
	sum=0;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>road[i].a>>road[i].b>>road[i].c
		>>road[i].p>>road[i].r;	
		sum+=road[i].r;	
	}
	for(int i=0;i<15;i++)		
		visited[i]=0;	
	minimum=MAX;
	visited[1]++;
	dfs(1,0);
	if(minimum==MAX)
		cout<<"impossible"<<endl;
	else cout<<minimum<<endl;
	return 0;
}

void dfs(int node,int currentCost){
	int tmp;
	if(currentCost>=sum||currentCost>=minimum)
		return;
	if(node==n){
		if(currentCost<minimum)
			minimum=currentCost;
		return;
	}
	for(int i=0;i<m;i++){
		if(road[i].a==node){
			if(visited[road[i].c])
				tmp=min(road[i].p,road[i].r);
			else tmp=road[i].r;		
			visited[road[i].b]++;
			dfs(road[i].b,currentCost+tmp);			
			visited[road[i].b]--;
		}
	}
	return;
}
