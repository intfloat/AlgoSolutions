#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int Initial();
int dir_x[]={-1,1,0,0};
int dir_y[]={0,0,1,-1};
const int LENTH=5;
struct Node{
	bool visited;
	int value,pre_x,pre_y;
	int x,y;
};
struct Nd{
	int x,y;
};
Node maze[LENTH][LENTH];
queue<Node> q; 
stack<Nd> s;
int main(){
	int tmp_x,tmp_y;
	Node tmp;
	Nd tp;
	Initial();
	while(q.empty()==false){
		tmp=q.front();
		if(tmp.x==4&&tmp.y==4)
			break;
		q.pop();
		for(int i=0;i<4;i++){
			tmp_x=dir_x[i]+tmp.x;
			tmp_y=dir_y[i]+tmp.y;
			if(tmp_x>=0&&tmp_x<LENTH&&tmp_y>=0&&tmp_y<LENTH
			   &&maze[tmp_x][tmp_y].visited==false&&maze[tmp_x][tmp_y].value==0){
				maze[tmp_x][tmp_y].visited=true;
				maze[tmp_x][tmp_y].pre_x=tmp.x;
				maze[tmp_x][tmp_y].pre_y=tmp.y;
				q.push(maze[tmp_x][tmp_y]);
			}
		}
	}
	tmp=maze[4][4];
	tp.x=4; tp.y=4;
	while(tmp.x!=0||tmp.y!=0){
		s.push(tp);
		tmp=maze[tmp.pre_x][tmp.pre_y];
		tp.x=tmp.x; tp.y=tmp.y;
	}
	cout<<"(0, 0)"<<endl;
	while(s.empty()==false){
		tp=s.top();
		cout<<"("<<tp.x<<", "<<tp.y<<")"<<endl;
		s.pop(); 
	}
	system("pause");
	return 0;
}

int Initial(){
	while(q.empty()==false)
		q.pop();
	while(s.empty()==false)
		s.pop();
	for(int i=0;i<5;i++)
	for(int j=0;j<5;j++){
		cin>>maze[i][j].value;
		maze[i][j].x=i; maze[i][j].y=j;
		maze[i][j].pre_x=-1;
		maze[i][j].pre_y=-1;
		maze[i][j].visited=false;
	}
	maze[0][0].visited=true;
	//maze[0][0].
	q.push(maze[0][0]);
	return 0;
}
