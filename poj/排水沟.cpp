#include<iostream>
#include<queue>
using namespace std;

bool augment();
 
//capacity of pipe
int capacity[205][205];
//previous pipe
int record[1005];
int n;
bool checked[205];
queue<int> q;

int main(){	
	int pipeNumber,maximum,minimum;
	int x,y,cap,tmpPre,tmpNext;
	while(cin>>pipeNumber>>n){
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			capacity[i][j]=0;
			//node[i][j].capacity=0;
			//node[i][j].pre=-1;
			record[i]=-1;
		}
		for(int i=0;i<pipeNumber;i++){
			cin>>x>>y>>cap;
			//if(cap>capacity[x][y])
			capacity[x][y]+=cap;
		}
		maximum=0;
		while(augment()==true){
			tmpPre=record[n];
			tmpNext=n;
			minimum=999999;
			while(tmpPre!=-1){
				if(capacity[tmpPre][tmpNext]<minimum)
					minimum=capacity[tmpPre][tmpNext];
				tmpNext=tmpPre;
				tmpPre=record[tmpPre];
			}
			tmpPre=record[n];
			tmpNext=n;		
			while(tmpPre!=-1){
				//更新残留网络 
				capacity[tmpPre][tmpNext]-=minimum;
				capacity[tmpNext][tmpPre]+=minimum;
				tmpNext=tmpPre;
				tmpPre=record[tmpPre];
			}
			maximum+=minimum;
		}
		cout<<maximum<<endl;
	}
	return 0;
}

bool augment(){
	bool havePath;
	for(int i=1;i<=n;i++)
		checked[i]=false;
	while(q.empty()==false)
		q.pop();
	checked[1]=true;
	q.push(1);
	havePath=false;
	//广搜寻找增广路径 
	while(q.empty()==false){
		int tmp=q.front();
		//找到增广路径则退出循环 
		if(tmp==n){
			havePath=true;	
			break;
		}	
		q.pop();
		for(int i=1;i<=n;i++){
			if(checked[i]==false&&capacity[tmp][i]>0){
				checked[i]=true;
				q.push(i);
				record[i]=tmp;
			}
		}
	}
	return havePath;
}
