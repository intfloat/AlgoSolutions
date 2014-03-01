//�����������Ϊ��ֵ�Ŀ������� 

#include<iostream>
#define MAX 1000
using namespace std;

int Quick_sort(int num[MAX],int l,int r);
int Partition(int num[MAX],int l,int r);

int len,num[MAX];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i=0;
	while(cin>>num[i])
		i++;
	len=i;
	Quick_sort(num,0,len-1);	
	//system("pause");
	return 0;
} 

int Quick_sort(int num[MAX],int l,int r){
	if(l>=r)
		return l;
	int pivot=l;
	//��ֵ���� 
	pivot=Partition(num,l,r);
	//����Ҫ��Ľ����� 
	for(int i=0;i<len;i++)
		cout<<num[i]<<" ";
	cout<<endl;	
	//��벿�ֽ��п������� 
	Quick_sort(num,l,pivot-1);
	//�Ұ벿�ֽ��п������� 
	Quick_sort(num,pivot+1,r);
	return 0;
}

int Partition(int num[MAX],int l,int r) {
	int tmp=num[l];
	while(l<r){
		//������ֵ����ߣ��ȶ��Ҳ����ɨ�� 
		while(num[r]>=tmp&&r>l)
			r--;
		if(r>l){
			num[l]=num[r];
			l++;
		}
		//�ٶ�������ɨ�� 
		while(num[l]<=tmp&&r>l)
			l++;
		if(r>l){
			num[r]=num[l];
			r--;
		}
	}
	//��ʱ����ָ���ָ��ͬһ��Ԫ�� 
	num[l]=tmp;
	return l;
}
