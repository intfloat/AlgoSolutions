#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
struct Node{
	int acquire;
	int price;
	int sell;
	friend bool operator< (Node n1,Node n2){
		return n1.price<n2.price;
	}
};
Node node[100005];
priority_queue<Node> q;
int main(){
	int t,sum,n;
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>node[i].acquire>>node[i].price>>node[i].sell;
		while(q.empty()==false)
			q.pop();
		for(int i=n-1;i>=0;i--){
			q.push(node[i]);
			//Node tmp=q.top();
			while(q.empty()==false&&node[i].acquire>0){
				Node tmp=q.top();
				q.pop();
				if(tmp.sell>node[i].acquire){
					sum+=node[i].acquire*tmp.price;
					tmp.sell-=node[i].acquire;
					node[i].acquire=0;
					q.push(tmp);
				}
				else{
					node[i].acquire-=tmp.sell;
					sum+=tmp.sell*tmp.price;
				}
			}
		}
		cout<<sum<<endl;
	}
	//system("pause");
	return 0;
}
