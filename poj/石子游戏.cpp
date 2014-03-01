#include<iostream>
using namespace std;
struct Node{
	int num[4];
};
Node node[11];
bool result[31][31][31][31];

int main(){
	int number[5];
	int n;
	for(int i=0;i<4;i++)
		cin>>number[i];
	//初始化 
	for(int i=0;i<=number[0];i++)
	for(int j=0;j<=number[1];j++)
	for(int k=0;k<=number[2];k++)
	for(int l=0;l<=number[3];l++){
		result[i][j][k][l]=false;
	}	
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++)
			cin>>node[i].num[j];
		result[node[i].num[0]][node[i].num[1]][node[i].num[2]][node[i].num[3]]=true;		
	}
	//通过动态规划自底向上建立结果 
	for(int i=0;i<=number[0];i++)
	for(int j=0;j<=number[1];j++)
	for(int k=0;k<=number[2];k++)
	for(int l=0;l<=number[3];l++){
		for(int p=0;p<n;p++){
			if(i-node[p].num[0]>=0&&j-node[p].num[1]>=0&&k-node[p].num[2]>=0&&l-node[p].num[3]>=0
			&& result[i-node[p].num[0]][j-node[p].num[1]][k-node[p].num[2]][l-node[p].num[3]]==false)
				result[i][j][k][l]=true;
		}
	}
	//判断并输出 
	if(result[number[0]][number[1]][number[2]][number[3]]==false)
		cout<<"lose"<<endl;
	else cout<<"win"<<endl;
	system("pause");
	return 0;
}
