#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int Company,Machine,maximum,Profit[30][30],path[30][30];
	int order,TotalProfit,Number[100],Goal[30][30];
	cin>>Company>>Machine;
	
	for(int i=0;i<=Company;i++)
	for(int j=0;j<=Machine;j++){
		Profit[i][j]=0;
		path[i][j]=0;
	}
		
	for(int i=1;i<=Company;i++)
	for(int j=1;j<=Machine;j++)
		cin>>Profit[i][j];
	for(int i=1;i<=Company;i++)
		Number[i]=0;
	//³õÊ¼»¯ 
	for(int i=0;i<=Company;i++)
		Goal[i][0]=0;
	for(int i=0;i<=Machine;i++)
		Goal[0][i]=0;
		
	//×´Ì¬×ªÒÆ 
	for(int i=1;i<=Company;i++)
	for(int j=1;j<=Machine;j++){
		maximum=0;
		for(int k=0;k<=j;k++){
			if(Goal[i-1][j-k]+Profit[i][k]>=maximum){
				//cout<<Goal[i-1][k]<<" "<<Profit[i][k]<<endl;
				maximum=Goal[i-1][j-k]+Profit[i][k];
				path[i][j]=k;
			}
		}
		//cout<<"maximum: "<<maximum<<endl;
		Goal[i][j]=maximum;
	}
	order=Machine;
	for(int i=Company;i>=1;i--){
		Number[i]=path[i][order];
		order-=path[i][order];
	}
	cout<<Goal[Company][Machine]<<endl;
	for(int i=1;i<=Company;i++){
		cout<<i<<" "<<Number[i]<<endl;
	}
	//system("pause");
	return 0;
}
