//��̬�����ظ����붼����������û�и�������� 
#include<iostream>
#include<stdio.h>
#define MAX 1001
using namespace std;
int find(int x);
void Initial();
struct Node{
	int pre;
};
struct TMP{
	int x,y;
};
Node node[MAX];
TMP tmp[MAX];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int x,y,rootx,rooty,rootnum,count,order;
	bool flag;
	count=0;
	while(cin>>x>>y&&x!=-1&&y!=-1){
		//����Ҳ��һ���� 
		if(x==0&&y==0){
			cout<<"Case "<<++count<<" is a tree."<<endl;
			continue;
		}
		flag=true;
		order=0;
		tmp[order].x=x; tmp[order].y=y; order++;
		Initial();
		if(x==y)
			flag=false;
		node[y].pre=x;
		//���ڵ���������� 
		node[x].pre=0;
		//ͳ�Ƶȼ������Ŀ 
		rootnum=1; 
		while(cin>>x>>y&&x&&y){
			for(int i=0;i<order;i++){
				if(tmp[i].x==x&&tmp[i].y==y){
					flag=false;
					break;
				}
			}
			tmp[order].x=x; tmp[order].y=y; order++;
			//�����Լ�ָ���Լ� 
			if(x==y)
				flag=false;
			//�Ѿ��ж��ⲻ��һ���� 
			if(flag==false)
				continue;			
			rootx=find(x);
			rooty=find(y);			
			if(rootx==rooty&&node[y].pre!=x)
				flag=false;			
			else if(rootx!=rooty){
				if(rootx==x&&node[x].pre==-1) rootnum++;
				if(rooty==y&&node[y].pre==-1) rootnum++;
				//�������������ڵ� 
				//if(y!=rooty)
				//	flag=false;
				//y���Ǹ��ڵ��Ȼ��������ĿҪ�� 
				if(node[y].pre!=-1&&node[y].pre!=0)
					flag=false;
				//�ϲ������ȼ��� 
				else{
					node[y].pre=rootx;		
					node[x].pre=0;		
					rootnum--;
				}
			}
		}
		//cout<<"root: "<<rootnum<<endl;
		if(flag==true&&rootnum==1)
			cout<<"Case "<<++count<<" is a tree."<<endl;
		//���������ڵ�����ȼ��඼����һ���� 
		else if(flag==false||rootnum!=1)
			cout<<"Case "<<++count<<" is not a tree."<<endl;
	}
	return 0;
}

int find(int x){
	if(node[x].pre==-1||node[x].pre==0)
		return x;
	int tmp=node[x].pre;
	node[x].pre=find(tmp);
	return node[x].pre;
}

void Initial(){
	for(int i=0;i<MAX;i++){
		node[i].pre=-1;
	}
	//rootnum=0;
}
