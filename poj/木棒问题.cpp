//ľ������ 
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

//��̬�滮˼���Ե������������ 
void init(){
	int tmp;
	for(int i=0;i<n;i++)
		RMQ[i][0]=0;                               //��iλ�ÿ�ʼ��1��������󳤶�Ϊ1
	for(int i=1;(1<<i)<=n;i++){
		for(int j=0;j<n;j++){
			RMQ[j][i]=RMQ[j][i-1];                 //��������ֳ������ֱַ����                              
			tmp=1<<(i-1);
			//������Сֵλ�� 
			if(j+tmp<n&&num[RMQ[j+tmp][i-1]]<num[RMQ[j][i]])
				RMQ[j][i]=RMQ[j+tmp][i-1];				
		}
	} 
	//�Լ�¼���ֵ��������г�ʼ�� 
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

//ʵ�����ֵ��ѯ 
int query_max(int left,int right){
	int i;
	int length=right-left+1;
	for(int i=0;(1<<(i+1))<=length;i++); 
	//���ص�����С���ֵ���±꣬���Ƚ�ʱӦ�ÿ����ߵ���ֵ��Դ�С 
	if(num[RMQ_MAX[left][i]]<num[RMQ_MAX[right-(1<<i)+1][i]])
		return RMQ_MAX[left][i];
	else return RMQ_MAX[right-(1<<i)+1][i];
}

//ʵ����Сֵ��ѯ 
int query_min(int left,int right){
	int i;
	int length=right-left+1;
	for(i=0;(1<<(i+1))<=length;i++);
	if(num[RMQ[left][i]]<num[RMQ[right-(1<<i)+1][i]])
		return RMQ[left][i];
	else return RMQ[right-(1<<i)+1][i];
} 

//Ѱ�Ҵ�left��right���������� 
int Hunt(int left,int right){
	//����߽���� 
	if(left>=right||left<0||right>n)
		return 0;
	int min,max;
	//��������ε���Сֵ��ѯ 
	min=query_min(left,right);
	//��������ε����ֵ��ѯ 
	max=query_max(left,right);
	//�������ֵ 
	if((max-min+1)>max_len)
		max_len=max-min+1;
	Hunt(left,min-1);
	Hunt(max+1,right);
	return 0;
}
