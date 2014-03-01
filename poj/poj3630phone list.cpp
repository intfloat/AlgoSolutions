//��http://acm.xtu.edu.cn/OnlineJudge/index.php/problem/read/id/1325��AC��
//����POJ�ϳ�ʱ�ˡ��������ˣ�����������ϰ�ֵ�����̬������ɾ���ġ���
//����ķ���Ӧ���ǽ�����̬������ֱ�ӽ�������ģ�� 
#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

//�ڵ㶨�� 
struct Node{
	Node* ptr[10];
	bool complete[10];
};

void insert(Node* root,char phone_num[15]);
void delete_tree(Node* root); 
void initial(Node* pt);
bool Unique=true;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	Node* root=NULL;
	int t,n;
	char phone_num[15];
	scanf("%d",&t);
	//cin>>t;
	while(t--){
		scanf("%d",&n);
		//cin>>n;
		Unique=true;
		root=new Node;
		initial(root);
		for(int i=0;i<n;i++){
			scanf("%s",phone_num);
			//cin>>phone_num;
			if(Unique==true)
				insert(root,phone_num);			
		}
		if(Unique==true)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		delete_tree(root);
	}
	system("pause");
	return 0;
}

//���нڵ�Ĳ������ 
void insert(Node* root,char phone_num[15]){
	int len=strlen(phone_num),cur=0;
	Node* tmp=root;	
	while(len--){
		int pos=phone_num[cur++]-'0';
		if(tmp->complete[pos]==true){
			Unique=false;
			return;
		}
		if(tmp->ptr[pos]==NULL){
			tmp->ptr[pos]=new Node;
			initial(tmp->ptr[pos]);
		}
		if(len==0)
			tmp->complete[pos]=true;
		tmp=tmp->ptr[pos];
	}
	for(int i=0;i<10;i++)
		if(tmp->ptr[i]!=NULL)
			Unique=false;			
}

//ɾ��ԭ�е��ֵ��� 
void delete_tree(Node* root){
	for(int i=0;i<10;i++){
		if(root->ptr[i]!=NULL)
			delete_tree(root->ptr[i]);
	}
	delete root;	
} 

//��ʼ��һ�������ɵĽڵ� 
void initial(Node* pt){
	for(int i=0;i<10;i++){
		pt->ptr[i]=NULL;
		pt->complete[i]=false;
	}
}
