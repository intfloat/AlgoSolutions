#include<iostream>
#include<string.h>
using namespace std;
void dfs(int x,int y);

const int dir_x[]={1,1,2,2,-1,-1,-2,-2};
const int dir_y[]={2,-2,1,-1,2,-2,1,-1};
bool avail[40][40],checked[40][40];
int des_x,des_y,counter;

int main(){
	
	int tmpx,tmpy,horse_x,horse_y;
	
	memset(avail,true,sizeof(avail));
	memset(checked,false,sizeof(checked));
	cin>>des_x>>des_y>>horse_x>>horse_y;	
	avail[horse_x][horse_y]=false;
	
	for(int i=0;i<8;i++){
		tmpx=horse_x+dir_x[i];
		tmpy=horse_y+dir_y[i];
		if(tmpx<0||tmpy<0)
			continue;
		avail[tmpx][tmpy]=false;
	}
	counter=0;
	dfs(0,0);
	cout<<counter<<endl;
	system("pause");
	return 0;
}

void dfs(int x,int y){
	if(x==des_x&&y==des_y){
		counter++;
		return;
	}
	if(x>des_x||y>des_y)
		return;
	if(checked[x+1][y]==false&&avail[x+1][y]==true){
		checked[x+1][y]=true;
		dfs(x+1,y);
		checked[x+1][y]=false;
	}
	
	if(checked[x][y+1]==false&&avail[x][y+1]==true){
		checked[x][y+1]=true;
		dfs(x,y+1);
		checked[x][y+1]=false;
	}
	return;
}
