#include<iostream>
#include<algorithm>
using namespace std;

void dfs(int number);
bool cmp(int a,int b){
	return a>b;
}

bool selected[20],goal;
int length,n;
int edge[20],colMin[100]; 

int main(){
	int t,sum;
	cin>>t;
	while(t--){
		goal=false;
		cin>>length;
		cin>>n;
		sum=0;
		for(int i=0;i<n;i++){
			cin>>edge[i];
			sum+=edge[i]*edge[i];
		}
		if(sum!=length*length){
			cout<<"no"<<endl;
			continue;
		}
		sort(edge,edge+n,cmp);
		for(int i=0;i<n;i++)
			selected[i]=false;
		for(int i=0;i<length;i++)
			colMin[i]=0;
		dfs(0);
		if(goal==true)
			cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	system("pause");
	return 0;
} 

void dfs(int number){
	if(number==n||goal==true){
		goal=true;
		return;
	}
	
	int minimumRow=100;
	int minimumCol;
	int pre=-1;
	bool find;
	
	for(int i=0;i<length;i++){
		if(colMin[i]<minimumRow){
			minimumRow=colMin[i];
			minimumCol=i;
		}
	}
	
	for(int i=0;i<n;i++){
		find=true;
		if(selected[i]==false&&((minimumRow+edge[i]-1)<length)&&((minimumCol+edge[i]-1)<length)){
			if(edge[i]==pre)
				continue;
			else pre=edge[i];
			for(int j=minimumCol;j<minimumCol+edge[i];j++){
				if(colMin[j]>minimumRow){					
					find=false;
					break;
				}
			}
			if(find==false)
				continue;
			for(int j=minimumCol;j<minimumCol+edge[i];j++)
				colMin[j]+=edge[i];
			selected[i]=true;
			dfs(number+1);
			//回溯的过程 
			for(int j=minimumCol;j<minimumCol+edge[i];j++)
				colMin[j]-=edge[i];
			selected[i]=false;
			if(goal==true)
				return;
		}
	}
	return;
}
