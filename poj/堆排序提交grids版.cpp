//������

#include<iostream>
#define MAX 1000
using namespace std;

int sift_down(int num[MAX],int i,int Size);
int swap(int num[MAX],int i,int j);
int BuildMaxHeap(int num[MAX],int Size);

int len;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i=0,num[MAX],CurrentSize;
	int n;
	cin>>n;
	while(cin>>num[i])
		i++;
	len=i;
	CurrentSize=len;
	//�������ֵ�� 
	BuildMaxHeap(num,len);
	//cout<<"������Ŷ��~"<<endl;	
	while(CurrentSize>1){
		//���Ѷ�Ԫ������ĩβ��Ԫ�ؽ��� 
		swap(num,0,CurrentSize-1);
		CurrentSize--;
		//����ɸѡ������ 
		sift_down(num,0,CurrentSize);
		//���ÿһ�ζѵ�����Ľ��
		/*for(i=0;i<len;i++)
			cout<<num[i]<<" ";
		cout<<endl; */
	}
	for(i=0;i<len;i++)
		cout<<num[i]<<endl;
	//cout<<endl; 
	return 0;
} 
int sift_down(int num[MAX],int i,int Size){
	int j=2*i+1;
	//iӦ��Ϊ��Ҷ��� 
	while(i<Size&&j<Size){
		//���ӽ���ֵ�������ӽ���ֵ 
		if(j+1<Size&&num[j+1]>num[j])
			j++;
		if(num[i]<num[j]){
			swap(num,i,j);
			i=j;
			j=2*i+1;
		}
		else
			return 0;
	}
	return 0;
}

int BuildMaxHeap(int num[MAX],int Size){
	int bottom=(Size-2)/2;
	for(int i=bottom;i>=0;i--){
		//ɸ�����ѵĹ��� 
		sift_down(num,i,Size);
	}
	return 0;
}

//Ԫ�ؽ����Ĺ��� 
int swap(int num[MAX],int i,int j){
	int tmp;
	tmp=num[j];
	num[j]=num[i];
	num[i]=tmp;
	return 0;
}
