#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,k,number[5005],f[5005][2],g[5005][2];
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>number[i];
	
	for(int i=0;i<n;i++)
	for(int j=0;j<2;j++){
		f[i][j]=0;
		g[i][j]=0;
	}
	
	for(int i=1;i<=k;i++){		
		for(int j=0;j<n;j++){
			f[j][0]=f[j][1];
			g[j][0]=g[j][1];
		}
		int sum=0;
		for(int j=0;j<i;j++)
			sum+=number[j];
		f[i-1][1]=sum;
		g[i-1][1]=sum;
		for(int j=i;j<n;j++){						
			f[j][1]=max(f[j-1][1],g[j-1][0])+number[j];
			g[j][1]=max(f[j][1],g[j-1][1]);
		}
	}
	cout<<g[n-1][1]<<endl;

	system("pause");
	return 0;
}
