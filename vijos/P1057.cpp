#include<iostream>
#include<algorithm>
#include<string.h>
#define MAX 1001
using namespace std;

int main(){
	int n,m;
	int goal=-1;
	int area[2][MAX];
	memset(area,0,sizeof(area));
	bool field;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>field;
			if(field==false)
				area[1][j]=0;
			else if(i==0 || j==0)
				area[1][j]=1;
			else
				area[1][j]=min(area[0][j-1],min(area[0][j],area[1][j-1]))+1;
			goal=max(area[1][j],goal);				
		}
		for(int k=0;k<m;k++)
			area[0][k]=area[1][k];
	}
	cout<<goal<<endl;
	system("pause");
	return 0;
}
