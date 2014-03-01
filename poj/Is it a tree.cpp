//变态啊，重复输入都不算树，有没有搞错！！！！ 
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
		//空树也是一棵树 
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
		//根节点进行特殊标记 
		node[x].pre=0;
		//统计等价类的数目 
		rootnum=1; 
		while(cin>>x>>y&&x&&y){
			for(int i=0;i<order;i++){
				if(tmp[i].x==x&&tmp[i].y==y){
					flag=false;
					break;
				}
			}
			tmp[order].x=x; tmp[order].y=y; order++;
			//不能自己指向自己 
			if(x==y)
				flag=false;
			//已经判定这不是一棵树 
			if(flag==false)
				continue;			
			rootx=find(x);
			rooty=find(y);			
			if(rootx==rooty&&node[y].pre!=x)
				flag=false;			
			else if(rootx!=rooty){
				if(rootx==x&&node[x].pre==-1) rootnum++;
				if(rooty==y&&node[y].pre==-1) rootnum++;
				//产生了两个父节点 
				//if(y!=rooty)
				//	flag=false;
				//y不是根节点必然不符合题目要求 
				if(node[y].pre!=-1&&node[y].pre!=0)
					flag=false;
				//合并两个等价类 
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
		//有两个父节点或多个等价类都不是一棵树 
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
