//һ��AC,��Ϊ�������໥��ϵ�Ĵ��ݷǳ���Ҫ 
#include<iostream>
#include<stdio.h>
#define MAX 50001
using namespace std;
int find(int x);
void Initial(int n);
struct Node{
	int pre,rank;
};
Node node[MAX];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,k,count,x,y,rootx,rooty,d;
	scanf("%d%d",&n,&k);
	count=0;
	Initial(n);
	while(k--){
		scanf("%d%d%d",&d,&x,&y);
		if(x>n||y>n){
			count++;
			//cout<<"out of bound!"<<endl; 
			continue;
		}
		rootx=find(x);
		rooty=find(y);
		//���ڵ���ͬ 
		if(rootx==rooty){
			if(d==1&&node[x].rank!=node[y].rank){ 
				count++;
				//cout<<"not the same"<<endl;
			}
			if(d==2&&(node[x].rank-node[y].rank+3)%3!=1){ 
				count++; 
				//cout<<"not be eaten"<<endl;
			}
		}
		//�ϲ������ȼ��� 
		else{
			 //�ı�����ָ�� 
			 node[rooty].pre=rootx;
			 //��3��Ϊ�˷�ֹ���ָ��� 
			 node[rooty].rank=(-node[y].rank-(d-1)+node[x].rank+3)%3;
		}
	}
	printf("%d\n",count);
	//system("pause");
	return 0;
} 

int find(int x){
	if(node[x].pre==x)
		return x;
	int tmp=node[x].pre;
	node[x].pre=find(tmp);
	node[x].rank=(node[x].rank+node[tmp].rank+3)%3;
	return node[x].pre;
}

void Initial(int n){
	for(int i=0;i<=n;i++){
		node[i].pre=i;
		node[i].rank=0;
	}
}
