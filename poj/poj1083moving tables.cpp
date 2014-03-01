#include<iostream>
#include<algorithm>
using namespace std;
struct Node {
	int x,y;	
};
int cmp(Node a,Node b){
	if(a.y==b.y)
		return a.x<b.x;
	return a.y<b.y;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	Node node[205];
	int t,n,tmp,minimumTime,minRoom,min;
	bool processEnd,selected[205];
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>node[i].x>>node[i].y;
			if(node[i].x%2==1)
				node[i].x++;
			if(node[i].y%2==1)
				node[i].y++;
			if(node[i].x>node[i].y){
				tmp=node[i].x;
				node[i].x=node[i].y;
				node[i].y=tmp;
			}
		}
		sort(node,node+n,cmp);
		//for(int i=0;i<n;i++)
		//	cout<<i<<": "<<node[i].y<<endl;
		processEnd=false;
		minimumTime=0;
		for(int i=0;i<n;i++)
			selected[i]=false;
		while(processEnd==false){
			processEnd=true;
			for(int i=0;i<n;i++){
				if(selected[i]==false){
					selected[i]=true;
					min=i;
					minRoom=node[i].y;
					processEnd=false;
					break;
				}
			}
			if(processEnd==true)
				break;
			for(int i=min+1;i<n;i++){
				if(selected[i]==false&&node[i].x>minRoom){
					selected[i]=true;
					minRoom=node[i].y;
				}
			}
			minimumTime++;
		}
		cout<<minimumTime*10<<endl;
	}
	//system("pause");
	return 0;
}
