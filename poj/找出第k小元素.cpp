//�ҳ���KС��Ԫ��

#include<iostream>
using namespace std;

int find_kthmin(int *num,int l,int r);
int Partition(int *num,int l,int r);

bool flag=false;
int kth_min,k;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i=0,*num;
	num=new int[1000];
	//����������� 
	cin>>k;
	while(cin>>num[i])
		i++;
	int len=i;
	//Ѱ�ҵ�kС������ 
	find_kthmin(num,0,len-1);
	cout<<kth_min<<endl;
	return 0;
} 

int find_kthmin(int *num,int l,int r){
	//kΪ�Ƿ�ֵ������ 
	if(k>len||k<=0||l>r){
		cout<<"can't found!"<<endl; 
		return 0;
	}
	if(flag==true)
		return 0;	
	//�����������Ϊ��ֵ���л��� 
	int pivot=Partition(num,l,r);
	if(pivot==k-1){
		flag=true;
		kth_min=num[pivot];
		return 0;
	}
	//Ŀ������������ 
	else if(pivot>k-1)
		find_kthmin(num,l,pivot-1);
	//Ŀ������������ 
	else if(pivot<k-1)
		find_kthmin(num,pivot+1,r);
	return 0;
}

int Partition(int *num,int l,int r){
	//��ʱ��¼��ֵ 
	int tmp=num[l];
	while(l!=r){
		//�ȴ��Ҳ࿪ʼ���� 
		while(num[r]>=tmp&&r>l)
			r--;
		if(r>l){
			num[l]=num[r];
			l++;
		}
		//�ٴ���࿪ʼ���� 
		while(num[l]<=tmp&&r>l)
			l++;
		if(r>l){
			num[r]=num[l];
			r--;
		}
	}
	//�����ֵ���ں��ʵ�λ�� 
	num[l]=tmp;
	//������ֵ���ڵ��±�λ�� 
	return l;
}
