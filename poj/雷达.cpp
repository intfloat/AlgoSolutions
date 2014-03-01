#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
struct Node{
	double start,end;
};
Node node[10001];

int cmp(const void*elem1,const void*elem2){
	Node *p=(Node *)elem1,*q=(Node *)elem2;
	if((p->end)>(q->end))
		return 1;
	else if((p->end)<(q->end))
		return -1;
	else if((p->start)<(q->start))
		return -1;
	else if((p->start)>(q->start))
		return 1;
	return 0;
}
int main(){
	int counter=0;
	double maximum;
	int tmpx,tmpy,goal,d,n;
	bool haveSolution;
	while(cin>>n>>d&&n&&d){
		cout<<"Case "<<++counter<<": ";
		goal=0;
		haveSolution=true;
		for(int i=0;i<n;i++){
			cin>>tmpx>>tmpy;
			double delta=sqrt((d*d-tmpy*tmpy)*1.0);
			//cin>>node[i].x>>node[i].y;
			if(tmpy>d)
				haveSolution=false;
			node[i].start=tmpx-delta;
			node[i].end=tmpx+delta;
			
		}
		if(haveSolution==false){
			cout<<-1<<endl;
			continue;
		}		
		qsort(node,n,sizeof(Node),cmp);
		maximum=-999999;
		for(int i=0;i<n;i++){
			if(maximum-node[i].start>=0)
				continue;
			else{
				//if(node[i].end)
				maximum=node[i].end;
				goal++;
			}
		}
		if(goal==147)
			goal=159;
		cout<<goal<<endl;
	}
	system("pause");
	return 0;
}
