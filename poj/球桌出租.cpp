#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
	int start,end;
	int money;
};
Node node[100001];
int maxProfit[100001];

int binarySearch(int i);
int cmp(const void *elem1,const void *elem2){
	Node *p=(Node *)elem1,*q=(Node *)elem2;
	if((p->end)!=(q->end))
		return (p->end)-(q->end);
	else return (q->start)-(p->start);
}
int main(){
	int n; 
	int number1,number2;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&node[i].start,&node[i].end,&node[i].money);
		maxProfit[i]=0;
	}
	qsort(node,n,sizeof(Node),cmp);
	for(int i=0;i<n;i++){
		if(i==0){
			maxProfit[i]=node[i].money;
			continue;
		}
		number1=maxProfit[i-1];
		int tmp=binarySearch(i);
		//没有符合条件的元素 
		if(tmp==-1)
			number2=node[i].money;
		else
			number2=maxProfit[tmp]+node[i].money;
		if(number1>number2)
			maxProfit[i]=number1;
		else maxProfit[i]=number2;
	}
	printf("%d\n",maxProfit[n-1]);
	system("pause");
	return 0;
}

//寻找比i结束早的最大元素 
int binarySearch(int i){
	int left=0,right=i-1;
	while(left<right){
		int middle=(left+right)/2;
		if(node[middle].end<node[i].start)
			left=middle+1;
		else if(node[middle].end>node[i].start)
			right=middle-1;
		else{
			int tmp=middle;
			while(node[tmp].end==node[middle].end)
				tmp++;
			return tmp;
		}
	} 
	if(left==0&&node[left].end>node[i].start)
		return -1;
	else if(node[left].end>node[i].start)
		return left-1;
	else return left;
}
