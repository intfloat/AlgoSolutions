#include<iostream>
using namespace std;

int cal(int num1,int num2,char op);
void init(int i);

int ori_num[55],num[55],n;
char ori_oper[55],oper[55];
int main(){
	int tmp_max,tmp_min,tem,tem_min,goal;
	int MAX[55],min[55][55],max[55][55];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>ori_oper[i]>>ori_num[i];
	for(int i=0;i<n;i++)
		MAX[i]=-999999;
	bool check=false;	
	for(int i=0;i<n;i++){
		//表示删除第i条边 
		init(i);
		for(int j=0;j<n;j++){
			min[j][j]=num[j];
			max[j][j]=num[j];
		}
		//增量从1开始增加 
		for(int j=1;j<n;j++){
			//从k到k+j的部分计算 
			for(int k=0;k<n-j;k++){
				tmp_max=-999999;
				tmp_min=9999999;
				for(int p=k;p<=k+j-1;p++){
					//最小值可能由最大值一方计算出来
					//最大值也可能由最小值一方计算出来 
					tem=cal(max[k][p],max[p+1][k+j],oper[p]);
					tem_min=cal(min[k][p],min[p+1][k+j],oper[p]);
					if(tem>tmp_max)
						tmp_max=tem;
					if(tem<tmp_min)
						tmp_min=tem;
					if(tem_min>tmp_max)
						tmp_max=tem_min; 
					if(tem_min<tmp_min)
						tmp_min=tem_min;
				}
				max[k][k+j]=tmp_max;
				min[k][k+j]=tmp_min;
			}
		}
		MAX[i]=max[0][n-1];
		//cout<<"MAX: "<<MAX[i]<<endl;
	}
	goal=-9999999;
	for(int i=0;i<n;i++){
		if(MAX[i]>goal)
			goal=MAX[i];
	}
	cout<<goal<<endl;
	for(int i=0;i<n;i++){
		if(MAX[i]==goal&&check==false){
			check=true;
			cout<<i+1;
		}		
		else if(MAX[i]==goal&&check==true)
			cout<<" "<<i+1;
	}
	cout<<endl;
	system("pause");
	return 0;
}

void init(int i){
	for(int j=0;j<n-1;j++)
		oper[j]=ori_oper[(j+i+1)%n];
		//num[j]=ori_num[(j+i)%n];		
	for(int j=0;j<n;j++)
		num[j]=ori_num[(j+i)%n];
}

int cal(int num1,int num2,char op){
	if(op=='t')
		return num1+num2;
	else if(op=='x')
		return num1*num2;
}
