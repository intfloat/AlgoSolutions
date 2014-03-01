#include<stdio.h>
#include<vector>
#include<iostream>
#define min(a,b) (a<b)?a:b
using namespace std;
int dfs(int order,int pr);
vector<int> edge[1501];
int num[1501][2];
int main(){
	int t,x,y,n;
	//int num[1501][2];
	while(cin>>t){
		//将上一个边表清空 
		for(int i=0;i<t;i++)
			edge[i].clear();
		for(int i=0;i<t;i++){
			scanf("%d:(%d)",&x,&n);
			while(n--){ 
				scanf("%d",&y);
				edge[x].push_back(y);
				edge[y].push_back(x);
			} 
		}
		//为根节点构造一个虚拟的父节点 
		dfs(0,-1);
		cout<<(int)(min(num[0][0],num[0][1]))<<endl;
	}
	system("pause");
	return 0;
}

int dfs(int order,int pr){
	int tmp;
	if(edge[order].size()==0){
		num[order][0]=0;
		num[order][1]=1;
		return 0;
	}
	//初始化为零 
	num[order][0]=num[order][1]=0;
	for(int i=0;i<edge[order].size();i++){
		tmp=edge[order][i];
		//对于父节点的情形不予考虑 
		if(tmp==pr)
			continue;
		dfs(tmp,order);
		//根节点空白则各子树的根节点必须填充 
		num[order][0]+=num[tmp][1];
		//根节点填充则各子树可填充或空白，选小者即可 
		num[order][1]+=min(num[tmp][0],num[tmp][1]);
	}
	num[order][1]++;
	return 0;
}
