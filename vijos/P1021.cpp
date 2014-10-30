#include<iostream>
/*
首先建立矩阵图，然后删去那些度数不够k的节点，不断更新直至没有节点被删除
统计还剩下多少节点，即可得到最终结果。 
*/
#include<algorithm>
#include<string.h>
#define MAX 205
using namespace std;

int main(){
	int n,k;
	bool matrix[MAX][MAX];
	int degree[MAX];
	bool valid[MAX];
	
	memset(valid,true,sizeof(valid));
	memset(degree,0,sizeof(degree));
	memset(matrix,false,sizeof(matrix));
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int tmp;
		while(cin>>tmp && tmp){
			if((tmp!=i) && (matrix[i][tmp]==false)){
				degree[i]++;
				matrix[i][tmp]=true;
				//无向图 
				if(matrix[tmp][i]==false){
					matrix[tmp][i]=true;
					degree[tmp]++;
				}
			}
		}
	}
	
	while(1){
		bool finish=true;
		for(int i=1;i<=n;i++){
			if(valid[i]==true && degree[i]<k){
				valid[i]=false;
				finish=false;
				for(int j=1;j<=n;j++){
					if(matrix[i][j]==true){
						matrix[i][j]=false;
						matrix[j][i]=false;
						degree[j]--;
					}
				}
			}
		}
		if(finish==true)
			break;
	}
	
	int goal=0;
	for(int i=1;i<=n;i++){
		if(valid[i]==true)
			goal++;
	}
	cout<<goal<<endl;
	system("pause");
	return 0;
}
