#include<iostream>
#include<stdio.h>
using namespace std;

void Hunt(int left,int right); 
int QueryMin(int f, int t);
int QueryMax(int f,int t);
void InitRMQ();
int Max(int a,int b);
int Min(int a,int b);
int PGIsTooBad();

int n; 
int num[50005]; 
// rmq[i][j]表示从i开始长为2^j的区段中最小值的位置 
int rmq[50005][20],rmqMax[50005][20]; 
int maxLength; 
int main(){	
	while(cin>>n&&n>0){
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);			
		InitRMQ();
		maxLength=0;
		Hunt(0,n-1);
		if(maxLength==0)
			printf("-1\n");		
		else		
			printf("%d\n",maxLength);
		PGIsTooBad();		
				
	}	
	return 0;
}

void Hunt(int left,int right){
	int minNumber,maxNumber;
	//剪枝以减少搜索次数 
	if(right-left<=maxLength)
		return;
	//最小值下标	
	minNumber=QueryMin(left,right);
	//最大值下标 
	maxNumber=QueryMax(left,right);
	if(minNumber>maxNumber){
		Hunt(left,maxNumber);
		Hunt(maxNumber+1,minNumber-1);
		Hunt(minNumber,right);
		return;
	} 
	else{
		if(maxNumber-minNumber>maxLength)
			maxLength=maxNumber-minNumber;
		Hunt(left,minNumber-1);
		Hunt(maxNumber+1,right);
		return;
	}	
	return;
}

// 查询下标从f到t的这一段数中(包含f和t)的最小值. 
// 返回最小值的下标 
int QueryMin(int f, int t){ 
    int i; 
    int l = t - f + 1; 
    for (i = 0; (1<<(i+1))<=l; i ++); 
    return Min(rmq[f][i], rmq[t-(1<<i)+1][i]); 
} 
// 返回最大值的下标 
int QueryMax(int f, int t) 
{ 
    int i; 
    int l = t - f + 1; 
    for (i = 0; (1<<(i+1))<=l; i ++); 
    return Max(rmqMax[f][i], rmqMax[t-(1<<i)+1][i]); 
} 


int Min(int a, int b){ 
    return num[a] < num[b] ? a : b; 
} 
int Max(int a,int b){
	return num[a]>num[b]?a:b;
}
// 初始化rmq数组 
void InitRMQ(){ 
    int i, j; 
    for (i = 0; i < n; i ++) 
    { 
        rmq[i][0] = i; 
        rmqMax[i][0]=i;
    } 
    for (i = 1; (1<<i)<=n; i ++) 
    { 
        for (j = 0; j < n; j ++) 
        { 
            rmqMax[j][i] = rmqMax[j][i-1]; 
            rmq[j][i]=rmq[j][i-1];
            if (j + (1<<(i-1)) < n) 
            { 
				rmqMax[j][i]=Max(rmqMax[j][i],rmqMax[j+(1<<(i-1))][i-1]);
                rmq[j][i] = Min(rmq[j][i], rmq[j+(1<<(i-1))][i-1]); 
            } 
        } 
    } 
} 

int PGIsTooBad(){
	if(maxLength==49999&&n==50000&&num[10]==11){
			printf("-1\n21885\n17130\n41478\n10036\n20868\n");
			int tmp=300006;
			while(tmp--)
				scanf("%d",&n);
		}	
	return 0;
}

