//这都出bug。。。。弱爆了啊。。。。 
#include<iostream>
using namespace std;
const int dir_x[]={1,0,1,-1};
const int dir_y[]={0,1,1,1};
void search(int x,int y);
int judge,goal_x,goal_y,board[21][21];
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<19;i++)
		for(int j=0;j<19;j++)
			cin>>board[i][j];
		judge=0;
		for(int i=0;i<19;i++){
			if(judge!=0)
				break;
			for(int j=0;j<19;j++){
				if(judge!=0)
					break;
				if(board[i][j]==0)
					continue;			
				search(i,j);
			}
		}
		cout<<judge<<endl;
		if(judge==1)
			cout<<goal_x<<" "<<goal_y<<endl;
		else if(judge==2)
			cout<<goal_x<<" "<<goal_y<<endl;
	}
	system("pause");
	return 0;
}

void search(int x,int y){
	for(int i=0;i<4;i++){
		int tmpx=x,tmpy=y;
		int counter=0;
		int tx=tmpx-dir_x[i],ty=tmpy-dir_y[i];
		if(tx>=0&&tx<19&&ty>=0&&ty<19&&board[tx][ty]==board[x][y])
			continue;
		while(tmpx>=0&&tmpx<19&&tmpy>=0&&tmpy<19&&board[tmpx][tmpy]==board[x][y]){
			counter++;
			tmpx+=dir_x[i];
			tmpy+=dir_y[i];
		}
		if(counter==5){
			judge=board[x][y];
			goal_x=x+1; goal_y=y+1;
			return;
		}
	}
	return;
}


