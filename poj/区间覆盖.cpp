#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	int l,r;
	int number;
};
Node node[100005];

int cmp(const void*elem1, const void*elem2){
	Node *p=(Node *)elem1,*q=(Node *)elem2;
	if(p->r!=q->r)
		return (p->r)-(q->r);
	else return (p->l)-(q->l);
}

int main(){
	int size,destination,left,right;
	int x,y;
	int maximum,minimum,tmp;
	bool first,haveSolution;
	cin>>destination;
	size=0;
	while(scanf("%d%d",&left,&right)){
		if(left==0&&right==0)
			break;
		//必然不符合要求的情形 
		if(right<=0||left>=destination)
			continue;
		node[size].l=left;
		node[size].r=right;
		node[size].number=999999;
		size++;
	}
	qsort(node,size,sizeof(Node),cmp);
	maximum=0;  
	first=true; 
	haveSolution=false;
	
	for(int i=0;i<size;i++){
		//if(node[i].l>maximum)
		//	continue;
		int tmp=i-1;
		if(node[i].l<=0)
			node[i].number=1;				
		while(tmp>=0&&node[tmp].r>=node[i].l){			
			if(node[tmp].number<node[i].number&&node[tmp].l>=node[i].l)
				node[i].number=node[tmp].number;
			else if(node[tmp].number+1<node[i].number&&node[tmp].l<node[i].l)
				node[i].number=node[tmp].number+1;										
			tmp--;
		}
		if(first==true&&node[i].l<=0){
			first=false;
			node[i].number=1;
		}
	}
	minimum=99999;
	for(int i=size-1;i>=0;i--){
		if(node[i].r<destination)
			break;
		if(node[i].number<minimum){
			minimum=node[i].number;
			haveSolution=true;
			//x=node[i].l;
			//y=node[i].r;
		}
	}
	if(haveSolution==false)
		cout<<"No solution"<<endl;
	else {		
		cout<<minimum<<endl;
	}
	system("pause");
	return 0;
}
