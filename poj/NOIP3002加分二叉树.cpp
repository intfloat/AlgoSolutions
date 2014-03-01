//加分二叉树，树形动态规划的经典 
#include<iostream>
using namespace std;
//对整棵树进行前序遍历 
int pre_travel(int start,int end);
int goal[50][50];
int n,root[50][50];
int main(){
	int score[50],max;
	while(cin>>n&&n){
		for(int i=0;i<n;i++)
			cin>>score[i];
		for(int i=0;i<n;i++){
			goal[i][i]=score[i];
			root[i][i]=i; 
			//针对左右子树有空的情形 
			for(int j=0;j<i;j++)
				goal[i][j]=1;
		}
		//表示间隔逐渐增大 
		for(int i=1;i<n;i++){
			for(int j=0;i+j<n;j++){
				max=-1;
				for(int k=j;k<=i+j;k++){			
					int tmp=goal[j][k-1]*goal[k+1][i+j]+score[k]; 
					if(tmp>max){
						max=tmp;
						root[j][i+j]=k;
					}
				} 
				goal[j][i+j]=max;
			}
		}	
		cout<<goal[0][n-1]<<endl;
		cout<<root[0][n-1]+1;
		pre_travel(0,root[0][n-1]-1);
		pre_travel(root[0][n-1]+1,n-1);
		cout<<endl;
		//system("pause");
	}
	return 0;
}

int pre_travel(int start,int end){	
	if(start<0||end>=n||start>end)
		return 0;
	cout<<" "<<root[start][end]+1;
	pre_travel(start,root[start][end]-1);
	pre_travel(root[start][end]+1,end);
	return 0;
}
