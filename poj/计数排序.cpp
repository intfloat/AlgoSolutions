//��������

#include<iostream>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int *num,*count,*goal,n;
	//����Ԫ������Ŀ 
	cin>>n;
	num=new int[n];
	goal=new int[n];
	count=new int[n];
	//����Ԫ�� 
	for(int i=0;i<n;i++)
		cin>>num[i];
	//���м��� 
	for(int i=0;i<n;i++){
		count[i]=0;
		for(int j=0;j<n;j++){
			if(num[j]<num[i])
				count[i]++;
		}		
	}
	//�����Ĺ���
	for(int i=0;i<n;i++)
		goal[count[i]]=num[i]; 
	//��������� 
	for(int i=0;i<n;i++)
		cout<<goal[i]<<" ";
	cout<<endl;
	return 0;
}
