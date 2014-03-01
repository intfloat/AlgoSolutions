#include<iostream>
/*
���Ƚ�������ͼ��Ȼ��ɾȥ��Щ��������k�Ľڵ㣬���ϸ���ֱ��û�нڵ㱻ɾ��
ͳ�ƻ�ʣ�¶��ٽڵ㣬���ɵõ����ս���� 
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
				//����ͼ 
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
