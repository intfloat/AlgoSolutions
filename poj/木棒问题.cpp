//木棍问题 
#include<iostream>
using namespace std;

int RMQ[50005][20],RMQ_MAX[50005][20];
int num[50005];
int n,max_len;

void init(); 
int query_max(int left,int right);
int query_min(int left,int right);
int Hunt(int left,int right);
 
int main(){
	//int n,max_len;
	while(cin>>n){
		for(int i=0;i<n;i++)
			cin>>num[i];
		max_len=-1;
		init();
		Hunt(0,n);
		cout<<max_len<<endl;
	}
	system("pause");
	return 0;
}

//动态规划思想自底向上求解问题 
void init(){
	int tmp;
	for(int i=0;i<n;i++)
		RMQ[i][0]=0;                               //从i位置开始的1个序列最大长度为1
	for(int i=1;(1<<i)<=n;i++){
		for(int j=0;j<n;j++){
			RMQ[j][i]=RMQ[j][i-1];                 //将子数组分成两部分分别求解                              
			tmp=1<<(i-1);
			//更新最小值位置 
			if(j+tmp<n&&num[RMQ[j+tmp][i-1]]<num[RMQ[j][i]])
				RMQ[j][i]=RMQ[j+tmp][i-1];				
		}
	} 
	//对记录最大值的数组进行初始化 
	for(int i=0;i<n;i++)
		RMQ_MAX[i][0]=0;
	for(int i=1;(1<<i)<=n;i++){
		for(int j=0;j<n;j++){
			RMQ_MAX[j][i]=RMQ_MAX[j][i-1];
			tmp=1<<(i-1);
			if(j+tmp<n&&num[RMQ_MAX[j+tmp][i-1]]>num[RMQ_MAX[j][i]])
				RMQ_MAX[j][i]=RMQ_MAX[j+tmp][i-1];
		}
	}
}

//实现最大值查询 
int query_max(int left,int right){
	int i;
	int length=right-left+1;
	for(int i=0;(1<<(i+1))<=length;i++); 
	//返回的是最小最大值的下标，但比较时应该看二者的数值相对大小 
	if(num[RMQ_MAX[left][i]]<num[RMQ_MAX[right-(1<<i)+1][i]])
		return RMQ_MAX[left][i];
	else return RMQ_MAX[right-(1<<i)+1][i];
}

//实现最小值查询 
int query_min(int left,int right){
	int i;
	int length=right-left+1;
	for(i=0;(1<<(i+1))<=length;i++);
	if(num[RMQ[left][i]]<num[RMQ[right-(1<<i)+1][i]])
		return RMQ[left][i];
	else return RMQ[right-(1<<i)+1][i];
} 

//寻找从left到right的最大区间段 
int Hunt(int left,int right){
	//到达边界情况 
	if(left>=right||left<0||right>n)
		return 0;
	int min,max;
	//进行区间段的最小值查询 
	min=query_min(left,right);
	//进行区间段的最大值查询 
	max=query_max(left,right);
	//更新最大值 
	if((max-min+1)>max_len)
		max_len=max-min+1;
	Hunt(left,min-1);
	Hunt(max+1,right);
	return 0;
}
