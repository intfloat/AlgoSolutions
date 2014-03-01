//³¬Ê±³¬µ½ËÀ°¡ÓÐÄ¾ÓÐ£¡£¡£¡£¡ 
#include<iostream>
#include<stdio.h>
#include<memory.h>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node *next;
};
Node node[1001];
Node* ptr[1001];
bool visited[10001];
int main(){
	queue<int> q;
	int t,x,y,N,Q,goal,tmp,len;
	bool find;
	Node *head;
	scanf("%d",&t);
	//cin>>t;
	while(t--){
		scanf("%d%d",&N,&Q);
		//cin>>N>>Q;
		for(int i=0;i<=N;i++){
			ptr[i]=node+i;
			node[i].data=i;
			node[i].next=NULL;
		}
		//memset(visited,N+1,false);
		for(int i=0;i<N-1;i++){
			scanf("%d%d",&x,&y);
			//cin>>x>>y;
			head=ptr[x];
		//	while(head->next!=NULL)
		//		head=head->next;
			head->next=new Node;
			head->next->next=NULL;
			head->next->data=y;
			ptr[x]=ptr[x]->next;
			
			head=ptr[y];
			//while(head->next!=NULL)
			//	head=head->next;
			head->next=new Node;
			head->next->next=NULL;
			head->next->data=x;
			ptr[y]=ptr[y]->next;
		}
		for(int i=0;i<Q;i++){
			scanf("%d%d",&x,&y);
			//cin>>x>>y;
			find=false;
			for(int i=0;i<=N;i++)
				visited[i]=false;
			//memset(visited,N+1,false);
			while(q.empty()==false)
				q.pop();
			q.push(x); visited[x]=true;			
			while(q.empty()==false){
				len=q.size();
				while(len--){
					tmp=q.front();		
					//cout<<"test: "<<tmp<<endl;			
					head=node+tmp;
					head=head->next;
					while(head!=NULL){
						if(visited[head->data]==false){
							q.push(head->data);
							visited[head->data]=true; 
							if(head->data==y){
								find=true;
								goal=tmp;
								break;
							}
						}
						head=head->next;
					}
					if(find==true)
						break;
					q.pop();
				}
				if(find==true)
					break;
			}
			printf("%d\n",goal);
			//cout<<goal<<endl;
		}
	}
	system("pause");
	return 0;
}
