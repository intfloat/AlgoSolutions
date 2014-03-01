#include<iostream>
using namespace std;
int main(){
	int n,num[105][105];
	cin>>n;
	for(int i=0;i<n;i++)
	for(int j=0;j<i+1;j++)
		cin>>num[i][j];
	for(int i=n-2;i>=0;i--)
	for(int j=0;j<=i;j++){
		if(num[i+1][j]>num[i+1][j+1])
			num[i][j]+=num[i+1][j];
		else
			num[i][j]+=num[i+1][j+1];
	}
	cout<<num[0][0]<<endl;
	system("pause");
	return 0;
}
