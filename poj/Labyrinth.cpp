#include<stdio.h>
#include<iostream>
#include<stack>
#define MAX 105
using namespace std;

int dfs();
bool edge(int i,int j);

struct Node{
	int x,y,dis,dir;
};

stack<Node> s;
int dir_x[]={0,0,-1,1};
int dir_y[]={1,-1,0,0};
char maze[MAX][MAX];
bool visited[MAX][MAX];
int Max_len,r,c;

int main(){
	int t;
	Node node,tem;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&t);	
	while(t--){
		scanf("%d%d",&c,&r);
		//cin>>c>>r;
		for(int i=0;i<r;i++){
			scanf("%s",maze[i]);
			//cin>>maze[i];
			//cout<<"test: "<<maze[i]<<endl;
		}
		//system("pause");
		while(s.empty()==false)
			s.pop();
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			visited[i][j]=false;
		Max_len=0;
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			if(maze[i][j]=='.'&&edge(i,j)==true){
				visited[i][j]=true;
				node.x=i; node.y=j; 
				node.dis=0; node.dir=0;
				s.push(node);
				dfs();
				//visited[i][j]=false; 
				//if(tmp>Max_len)
				//	Max_len=tmp;
				/*while(s.empty()==false){
					tem=s.top();
					visited[tem.x][tem.y]=false;
					s.pop();
				}*/			
			}
		}
		printf("Maximum rope length is %d.\n",Max_len);
	}
	//system("pause");
	return 0;
}

int dfs(){
	int tmp_x,tmp_y;	
	Node tmp,tm;
	bool find;
	//node.x=i; node.y=j; node.dis=0;
	while(s.empty()==false){
		tmp=s.top();
		//cout<<"test: "<<tmp.x<<" "<<tmp.y<<endl;
		if(tmp.dir>=4){
			//s.pop();
			visited[tmp.x][tmp.y]=false;
			s.pop();
			continue;
		}
		find=false;
		for(int k=tmp.dir;k<4;k++){
			cout<<"test: "<<tmp.x<<" "<<tmp.y<<" "<<tmp.dir<<endl;
			tmp_x=tmp.x+dir_x[k]; tmp_y=tmp.y+dir_y[k];
			if(tmp_x>=0&&tmp_x<r&&tmp_y>=0&&tmp_y<c
			   &&visited[tmp_x][tmp_y]==false&&maze[tmp_x][tmp_y]=='.'){
					find=true;
					tm.x=tmp_x; tm.y=tmp_y;
					tm.dis=tmp.dis+1;
					tm.dir=0;
					tmp.dir++;
					s.pop();
					s.push(tmp);
					visited[tmp_x][tmp_y]=true;
					if(tm.dis>Max_len)
						Max_len=tm.dis;
					s.push(tm);
					break;
					//递归深搜的过程 
					//dfs();
					//回溯的过程  
					//visited[tmp_x][tmp_y]=false;
					//s.pop();
			}
		}
		if(find==false){
			s.pop();
			visited[tmp.x][tmp.y]=false;
		}
	}
	//visited[tmp.x][tmp.y]=false;
	//s.pop();
	return 0;
}

bool edge(int i,int j){
	int count=0,tmp_x,tmp_y;
	for(int k=0;k<4;k++){
		tmp_x=i+dir_x[k]; tmp_y=j+dir_y[k];
		if(tmp_x>=0&&tmp_x<r&&tmp_y>=0&&tmp_y<c&&maze[tmp_x][tmp_y]=='#')
			count++;
	}	
	if(count==3)
		return true;
	return false;
}
