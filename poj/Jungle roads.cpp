#include<iostream>
#define MAX 9999999
using namespace std;
int Initial(int n);
bool visited[30];
int path[30][30];
int main(){
	int n,num,tmp_order,tmp_dis,mini,sum,m;
	char ch1;
	while(cin>>n&&n){
		Initial(n);
		for(int i=0;i<n-1;i++){
			cin>>ch1>>m;
			num=ch1-'A';
			while(m--){
				cin>>ch1>>tmp_dis;
				tmp_order=ch1-'A';
				if(path[num][tmp_order]>tmp_dis){
					path[num][tmp_order]=tmp_dis;
					path[tmp_order][num]=tmp_dis;
				}
			}
		}
		visited[0]=true; sum=0;
		for(int i=0;i<n-1;i++){
			mini=MAX;
			for(int j=0;j<n;j++)
			for(int k=0;k<n;k++){
				if(visited[j]==true&&visited[k]==false&&path[j][k]<mini){
					mini=path[j][k];
					tmp_order=k;
				}
			}
			sum+=mini;
			visited[tmp_order]=true;
		}
		cout<<sum<<endl;
	}
	system("pause");
	return 0;
} 

int Initial(int n){
	for(int i=0;i<n;i++){
		visited[i]=false;
		for(int j=0;j<n;j++)
			path[i][j]=MAX;
	}
	return 0;
}
