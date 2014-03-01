#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

struct Node{
	int start,end;
	int weight;
};
Node node[200005];
int n,m,dis[200005],total;
int startPosition[200005];

void shortPath(int source); 

//±È½Ïº¯Êý 
int cmp(const void*elem1,const void *elem2){
	Node *p=(Node *)elem1,*q=(Node *)elem2;
	if((p->start)==(q->start)){
		if((p->end)==(q->end))
			return (p->weight)-(q->weight);
		return (p->end)-(q->end);
	}
	return (p->start)-(q->start);
}

int main(){
	int minimum;
	int x,y,wei;
	int miniDisFrom1[20005],miniDisFromN[20005];
	scanf("%d%d",&n,&m);
	total=0;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&wei);
		
		node[total].start=x; node[total+m].start=y;
		node[total].end=y; node[total+m].end=x;
		node[total].weight=wei; node[total+m].weight=wei;
		total++;
	}
	total=2*m;
	qsort(node,total,sizeof(Node),cmp);
	for(int i=0;i<=n;i++)
		startPosition[i]=-1;
	for(int i=0;i<total;i++){
		if(startPosition[node[i].start]==-1){
			startPosition[node[i].start]=i;
			//cout<<"start: "<<node[i].start<<endl;
		}
	}
	shortPath(1);
	for(int i=0;i<=n;i++){
		miniDisFrom1[i]=dis[i];
		//cout<<"mini: "<<dis[i]<<endl;
	}
	shortPath(n);
	for(int i=0;i<=n;i++)
		miniDisFromN[i]=dis[i];
	//cout<<"mini: "<<miniDisFromN[1]<<endl;
	minimum=9999999;
	for(int i=0;i<total;i++){
		int tmp1=miniDisFromN[1]+2*node[i].weight;
		int tmp2=miniDisFrom1[node[i].start]+miniDisFromN[node[i].end]+node[i].weight;
		if(tmp1<minimum&&tmp1>miniDisFromN[1])
			minimum=tmp1;
		if(tmp2<minimum&&tmp2>miniDisFromN[1])
			minimum=tmp2;
		
	}
	printf("%d\n",minimum);
	system("pause");
	return 0;
}

void shortPath(int source){
	queue<int> q;
	bool inQueue[200005];
	while(q.empty()==false)
		q.pop();
	for(int i=0;i<=n;i++){
		inQueue[i]=false;
		dis[i]=999999;
	}
	q.push(source);
	dis[source]=0;
	inQueue[source]=true;
	while(q.empty()==false){
		int tmp=q.front();
		inQueue[tmp]=false;
		q.pop();
		int tem=startPosition[tmp];		
		for(int i=tem;i<total&&node[i].start==tmp;i++){
			if(dis[node[i].end]>dis[node[i].start]+node[i].weight){
				dis[node[i].end]=dis[node[i].start]+node[i].weight;
				if(inQueue[node[i].end]==false){
					inQueue[node[i].end]=true;
					q.push(node[i].end);
				}
			}
		}
	}
	return;
}
