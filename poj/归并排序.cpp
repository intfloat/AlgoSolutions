//��·�鲢����

#include<iostream>
#define MAX 1000
using namespace std;

int Merge_sort(int num[MAX],int l,int r);
int Merge(int num[MAX],int l,int mid,int r);

int len; 
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i=0,num[MAX];
	while(cin>>num[i])
		i++;
	len=i;
	Merge_sort(num,0,len-1);
	return 0;
} 

int Merge_sort(int num[MAX],int l,int r){
	if(l>=r)
		return 0;
	int mid=(r+l)/2;
	//��벿�ֽ��й鲢���� 
	Merge_sort(num,l,mid);
	//�Ұ벿�ֽ��й鲢���� 
	Merge_sort(num,mid+1,r);
	//�������ֹ鲢 
	Merge(num,l,mid,r);
	//���ÿһ�ι鲢��Ľ��
	for(int i=0;i<len;i++)
		cout<<num[i]<<" ";
	cout<<endl; 
	return 0;
}

int Merge(int num[MAX],int l,int mid,int r){
	int *tmp;
	tmp=new int[r-l+1];
	int tmp_l=l,tmp_r=mid+1,i=0;
	//����Ѱ����Сֵ���鲢�Ĺ��� 
	while(tmp_l<=mid&&tmp_r<=r){
		if(num[tmp_l]<num[tmp_r])
			tmp[i++]=num[tmp_l++];
		else
			tmp[i++]=num[tmp_r++];
	}
	//����������ʣ��Ԫ�� 
	if(tmp_l<=mid){
		while(tmp_l<=mid)
			tmp[i++]=num[tmp_l++];
	}
	//����������ʣ��Ԫ�� 
	else if(tmp_r<=r){
		while(tmp_r<=r)
			tmp[i++]=num[tmp_r++];
	}
	for(i=0;i<r-l+1;i++)
		num[i+l]=tmp[i];
	delete []tmp;
	return 0;
} 
