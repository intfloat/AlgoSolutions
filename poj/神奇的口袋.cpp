#include<iostream>
#include<stdlib.h>
#define MAX 50
using namespace std;
int t,Count;
int weight[MAX];
int dfs(int i,int sum);
int cmp(const void *elem1,const void*elem2){
	return (*(int *)elem1-*(int *)elem2);
}
int main(){
	cin>>t;
	for(int i=0;i<t;i++)
		cin>>weight[i];
	qsort(weight,t,sizeof(int),cmp);
	Count=0;
	dfs(0,0);
	cout<<Count<<endl;
	system("pause");
	return 0;
}

int dfs(int i,int sum){
	if(sum>40||i>t)
		return 0;
	if(sum==40){
		Count++;
		return 0;
	}
	for(int j=0;j<2;j++){
		//sum+=weight[i]*j;
		dfs(i+1,sum+weight[i]*j);
		//sum-=weight[i]*j;
	}
	return 0;
}
