#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

void calculateValue(int i);

double value[1001][1001];
int row,column;
double maxValue[1005],maxReverseValue[1005];

int main(){	
	scanf("%d%d",&row,&column);
	for(int i=0;i<row;i++)
	for(int j=0;j<column;j++)
		scanf("%lf",&value[i][j]);
	for(int i=0;i<column;i++){
		/*if(i!=0){
			for(int j=0;j>row;j++)
				value[j][i]+=value[j][i-1];
		}*/
		calculateValue(i);
		for(int j=0;j<row;j++){
			if(maxValue[j]>maxReverseValue[j])
				value[j][i]=maxValue[j];
			else value[j][i]=maxReverseValue[j];
		}
	}
	cout<<fixed<<setprecision(0)<<value[row-1][column-1]<<endl;
	//printf("%f\n",value[row-1][column-1]);
	system("pause");
	return 0;
}

void calculateValue(int i){
	//maxValue[0]=value[0][i];
	//对第一列作特殊处理 
	if(i==0){
		maxValue[0]=value[0][0];
		for(int j=1;j<row;j++) 
			maxValue[j]=maxValue[j-1]+value[j][i];
		for(int j=row-1;j>=0;j--)
			maxReverseValue[j]=-9999999;
		return;
	}	
	//计算maxValue 
	maxValue[0]=value[0][i]+value[0][i-1];
	for(int j=1;j<row;j++){
		if(maxValue[j-1]>value[j][i-1])
			maxValue[j]=maxValue[j-1]+value[j][i];
		else maxValue[j]=value[j][i]+value[j][i-1];
	}	
	//计算maxReverseValue 
	maxReverseValue[row-1]=value[row-1][i]+value[row-1][i-1];
	for(int j=row-2;j>=0;j--){
		if(maxReverseValue[j+1]>value[j][i-1])
			maxReverseValue[j]=maxReverseValue[j+1]+value[j][i];
		else maxReverseValue[j]=value[j][i]+value[j][i-1];
	}
	return;
}
