//��������

#include<iostream>
#include<stdio.h>
#define MAX 500005
using namespace std;
int merge_sort(int num[MAX],int l,int r);
int merge(int num[MAX],int l,int r,int mid);
int tmp[MAX];
long long Count=0;

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,*num;
	while(scanf("%d",&n)&&n){
		Count=0;
		num=new int[n+5];
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		merge_sort(num,0,n-1);
		cout<<Count<<endl;
		//for(int i=0;i<n;i++)
		//	cout<<num[i]<<" ";
		//cout<<endl;
		//system("pause");
		delete [] num;
	}
	return 0;
}


//�鲢����Ļ�����ܣ��ڹ鲢�Ĺ����м��� 
int merge_sort(int num[MAX],int l,int r){
	if(l>=r||l<0||r>=MAX)
		return 0;
	int mid=(l+r)/2;
	merge_sort(num,l,mid);
	merge_sort(num,mid+1,r);
	merge(num,l,r,mid);
	return 0;
} 

//��������������ϲ��Ĺ��� 
int merge(int num[MAX],int l,int r,int mid){
	int i=0,tmp_l=l,tmp_r=mid+1;
	while(tmp_l<=mid&&tmp_r<=r){
		if(num[tmp_l]<=num[tmp_r])
			tmp[i++]=num[tmp_l++];
		else{
			tmp[i++]=num[tmp_r++];
			//���������Ĺؼ�֮���� 
			Count+=mid-tmp_l+1;
		}
	}	
	if(tmp_l<=mid){
		while(tmp_l<=mid)
			tmp[i++]=num[tmp_l++];
	}
	else if(tmp_r<=r){
		while(tmp_r<=r)
			tmp[i++]=num[tmp_r++];
	}
	for(int j=0;j<r-l+1;j++)
		num[l+j]=tmp[j];
	return 0;	
}
