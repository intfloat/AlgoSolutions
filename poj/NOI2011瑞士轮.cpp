#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void merge(int number);
struct Node{
	int score,wei;
	int order;
};
Node node[100001],winner[50001],loser[50001];

int cmp(const void*ele1, const void* ele2){
	Node *p=(Node *)ele1,*q=(Node *)ele2;
	//°´ÕÕ·ÖÊýµÄ½µÐòÅÅ 
	if((p->score)!=(q->score))
		return (q->score)-(p->score);
	//°´ÕÕ±àºÅµÄ½µÐòÅÅ 
	else return (p->order)-(q->order);
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,cycle,query,total; 
	cin>>n>>cycle>>query;
	total=2*n;
	for(int i=0;i<total;i++){
		scanf("%d",&node[i].score);
		//cin>>node[i].score;
		node[i].order=i;
	}
	for(int i=0;i<total;i++)
		scanf("%d",&node[i].wei);
		//cin>>node[i].wei;
	qsort(node,total,sizeof(Node),cmp);
	
	for(int i=0;i<cycle;i++){
		for(int j=0;j<n;j++){
			if(node[2*j].wei>node[2*j+1].wei){
				winner[j]=node[2*j];
				winner[j].score++;
				loser[j]=node[2*j+1];
			}
			else{
				winner[j]=node[2*j+1];
				winner[j].score++;
				loser[j]=node[2*j];
			}
		}
		merge(n);
	}
	cout<<node[query-1].order+1<<endl;
	//system("pause");
	return 0;
}

void merge(int number){
	int win_pos=0,los_pos=0,node_pos=0;
	while(win_pos<number&&los_pos<number){
		if(winner[win_pos].score>loser[los_pos].score)
			node[node_pos++]=winner[win_pos++];		
		else if(winner[win_pos].score==loser[los_pos].score){
			if(winner[win_pos].order<loser[los_pos].order)
				node[node_pos++]=winner[win_pos++];
			else node[node_pos++]=loser[los_pos++];
		}
		else
			node[node_pos++]=loser[los_pos++];
	}
	if(win_pos<number){
		for(int i=win_pos;i<number;i++)
			node[node_pos++]=winner[win_pos++];
	}
	if(los_pos<number){
		for(int i=los_pos;i<number;i++)
			node[node_pos++]=loser[los_pos++];
	}
	return;
}
