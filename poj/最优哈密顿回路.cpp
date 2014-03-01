#include<iostream>
#include<vector>
using namespace std;

vector<int> record;

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		cin>>path[i][j];
	int tmp=1<<n;
	
	//初始化 
	for(int i=0;i<tmp;i++)
		minDistance[i]=999999;
	//按照1的个数进行枚举 
	for(int i=1;i<n;i++){
		//返回所有1个数为i的状态 
		dfs(i);
		int len=record.size();
		for(int j=0;j<len;j++){
			number=record[j];
			for(int k=0;k<n;k++){
				//第k位为0的情形 
				if(number&(1<<k)==1){
					temp=number&(~(1<<k));
					if(minDistance[temp]+path[k][])
				}
			}
		} 
	}
	system("pause");
	return 0;
}
