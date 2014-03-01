//典型的矩阵乘法问题
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,neck[105];
	int energy[105][105];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>neck[i];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		energy[i][j]=0;
	for(int i=1;i<n;i++)
	for(int j=0;j<n;j++){
		for(int k=j;k<i+j;k++)
			energy[j][(i+j)%n]=max(energy[j][(i+j)%n],energy[j][k%n]+energy[(k+1)%n][(i+j)%n]+neck[j]*neck[(k+1)%n]*neck[(i+j+1)%n]);
	}
	int goal=0;	
	for(int i=0;i<n;i++)
		goal=max(energy[i][(i+n-1)%n],goal);
	cout<<goal<<endl;
	system("pause");
	return 0;
} 
