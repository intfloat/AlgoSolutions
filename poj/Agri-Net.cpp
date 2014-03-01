//最小生成树的基本问题 
#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,sum,cost[101][101],mini,tmp;
	bool visited[105];
	while(cin>>n){
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
			//cin>>cost[i][j];
			visited[i]=false;
		}
		visited[0]=true; sum=0;
		//Prim算法的搜索过程，采用最简单的枚举算法即可 
		for(int i=0;i<n-1;i++){
			mini=999999;
			for(int k=0;k<n;k++){
				if(visited[k]==false)
					continue;
				for(int j=0;j<n;j++){
					if(visited[j]==false&&cost[k][j]<mini){
						mini=cost[k][j];
						tmp=j;
					}
				}
			}
			sum+=mini;
			visited[tmp]=true;
		}
		cout<<sum<<endl;
	}	
	return 0;
}
