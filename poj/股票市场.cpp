#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
	int price,pre,sell;
};
Node node[100005];

struct queryNode{
	int acquire,sell;
};
queryNode query[100005];

int cmp(const void*elem1, const void*elem2){
	Node *p=(Node *)elem1,*q=(Node *)elem2;
	return (p->price)-(q->price);
}

int main(){
	int t,sum,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&query[i].acquire,&node[i].price,&query[i].sell);
			node[i].sell=query[i].sell;
			node[i].pre=i;
		}
		qsort(node,n,sizeof(Node),cmp);
		sum=0;
		for(int i=n-1;i>=0;i--){
			int index=node[i].pre;
			while(index>=0&&node[i].sell>0){
				if(node[i].sell>query[index].acquire){
					sum+=(node[i].price)*(query[index].acquire);
					//cout<<"enough: "<<(node[i].price)*(query[index].acquire)<<endl;
					//cout<<index<<endl;
					node[i].sell-=query[index].acquire;
					query[index].acquire=0;
					//if(index>0)
					//	node[index].pre=node[node[index].pre-1].pre;
					//else
					//	node[index].pre=-1;										
					//index=node[index].pre;
					index--;
					//cout<<"index after change "<<index<<endl;
				}
				else{
					sum+=node[i].sell*node[i].price;
					//cout<<"not enough: "<<node[i].sell*node[i].price<<endl;
					//cout<<index<<endl;
					//cout<<node[i].sell<<" "<<query[index].acquire<<endl;
					query[index].acquire-=node[i].sell;
					node[i].sell=0;
					node[i].pre=index;
				}
			}
		}
		printf("%d\n",sum);
	}
	system("pause");
	return 0;
}
