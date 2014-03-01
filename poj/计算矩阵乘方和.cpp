#include<iostream>
using namespace std;
struct Node{
	int num[31][31];
};
Node matrix; 
int n,k,m;

//����һ�������n�η� 
Node Multiply(Node* tmp,int n);
Node add(Node tmp1,Node tmp2);
Node multi(Node tmp1,Node tmp2);
Node func(int n);
void Mode(Node* tmp);


int main(){
	Node goal;
	//�������� 
	cin>>n>>k>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		cin>>matrix.num[i][j];
	goal=func(k);
	Mode(&goal);
	
	//��������� 
	for(int i=0;i<n;i++){		
		for(int j=0;j<n;j++){			
			cout<<goal.num[i][j]<<" ";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}

//�򵥵ľ���ӷ� 
Node add(Node tmp1,Node tmp2){
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		tmp1.num[i][j]+=tmp2.num[i][j];
	Mode(&tmp1);
	return tmp1;
} 

//�򵥾���˷� 
Node multi(Node tmp1,Node tmp2){
	Node tmp;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
		tmp.num[i][j]=0;
		for(int k=0;k<n;k++){
			tmp.num[i][j]+=tmp1.num[i][k]*tmp2.num[k][j];
			tmp.num[i][j]%=m;
		}
	}
	Mode(&tmp);
	return tmp;
} 

//�����۰����ָ�������n�η� 
Node Multiply(Node* tmp,int n){
	Node dest;
	if(n==1)
		return matrix;
	if(n%2==0){
		dest=Multiply(tmp,n/2);
		Mode(&dest);
		dest=multi(dest,dest);
		Mode(&dest);
	}
	else{
		dest=Multiply(tmp,n/2);
		Mode(&dest);
		dest=multi(dest,dest);
		Mode(&dest);
		dest=multi(dest,matrix);
		Mode(&dest);
	}
	return dest;
}

//�����ļ��� 
Node func(int n){
	Node tmp1,tmp2;
	if(n==1)
		return matrix;
	//�۰�����Լӿ��ٶ� 
	if(n%2==0){
		tmp1=func(n/2);
		Mode(&tmp1);
		tmp2=Multiply(&matrix,n/2);
		Mode(&tmp2);
		tmp2=multi(tmp1,tmp2);
		Mode(&tmp2);
		tmp1=add(tmp1,tmp2);
	}
	else{
		tmp1=func(n-1);
		Mode(&tmp1);
		tmp2=Multiply(&matrix,n);
		Mode(&tmp2);
		tmp1=add(tmp1,tmp2);
	}
	Mode(&tmp1);
	return tmp1;
} 

//ȡģ�Ĺ���                
void Mode(Node* tmp){
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		tmp->num[i][j]=tmp->num[i][j]%m;
}
