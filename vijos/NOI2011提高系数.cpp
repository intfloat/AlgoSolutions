#include<iostream>
using namespace std;
int calculate(int base,int number);
int a,b,k,n,m,combi[1001][1001];
int main(){
	cin>>a>>b>>k>>n>>m;
	for(int i=0;i<=k;i++)
	for(int j=0;j<=k;j++)
		combi[i][j]=-1;
	calculate(k,n);
	
	combi[k][n]%=10007;
	for(int i=0;i<n;i++){
		combi[k][n]*=a%10007;
		combi[k][n]%=10007;
	}
	for(int i=0;i<m;i++){
		combi[k][n]*=b%10007;
		combi[k][n]%=10007;
	}
	cout<<combi[k][n]%10007<<endl;
	system("pause");
	return 0;
}

int calculate(int base,int number){
	if(combi[base][number]!=-1)
		return combi[base][number];
	if(base==number||number==0){
		combi[base][number]=1;
		return combi[base][number];
	}
	combi[base][number]=calculate(base-1,number)+calculate(base-1,number-1);
	combi[base][number]%=10007;
	return combi[base][number];
}
