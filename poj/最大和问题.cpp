#include<iostream>
using namespace std;
int main(){
	int n,k,sum,goal[50005];
	int num[50005],next_MAX[50005],MAX[50005];
	int num1,num2;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>num[i];
	for(int i=0;i<n;i++){
		MAX[i]=0;
		next_MAX[i]=0;
	}
	for(int i=1;i<=k;i++){
		sum=0;
		//对前一部分进行初始化
		for(int p=0;p<n;p++)
			MAX[p]=next_MAX[p]; 
		for(int j=0;j<i;j++)
			sum+=num[j];
		//MAX[i-1]=goal[i-1];
		next_MAX[i-1]=sum;
		goal[i-1]=sum;
		//对后一部分采用动态规划求解 
		for(int j=i;j<n;j++){
			num1=num[j]+goal[j-1];
			num2=num[j]+MAX[j-1];
			if(num1>num2)
				goal[j]=num1;
			else goal[j]=num2;
			if(goal[j]>next_MAX[j-1])
				next_MAX[j]=goal[j];
			else next_MAX[j]=next_MAX[j-1];
		}
	}
	cout<<next_MAX[n-1]<<endl;
/*	int tmp_max=-9999999;
	for(int i=k-1;i<n;i++){
		if(next_MAX[i]>tmp_max)
			tmp_max=next_MAX[i];
	}
	cout<<tmp_max<<endl;*/
//	system("pause");
	return 0;
}									
