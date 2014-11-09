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
		//����һ���߱���� 
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
		//Ϊ���ڵ㹹��һ������ĸ��ڵ� 
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
	//��ʼ��Ϊ�� 
	num[order][0]=num[order][1]=0;
	for(int i=0;i<edge[order].size();i++){
		tmp=edge[order][i];
		//���ڸ��ڵ�����β��迼�� 
		if(tmp==pr)
			continue;
		dfs(tmp,order);
		//���ڵ�հ���������ĸ��ڵ������� 
		num[order][0]+=num[tmp][1];
		//���ڵ�����������������հף�ѡС�߼��� 
		num[order][1]+=min(num[tmp][0],num[tmp][1]);
	}
	num[order][1]++;
	return 0;
}
