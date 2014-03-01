#include<iostream>
#include<queue>
using namespace std;

void bfs();
void swap(int record[],int pos1,int pos2);
int getNumber(int record[]);

struct Node{
	int number,pos;
};
queue<Node> q;
int init,goal,step;
bool checked[1000005][6];

int main(){
	Node begin;
	cin>>init>>goal;
	begin.number=init;
	begin.pos=1;
	step=0;
	while(q.empty()==false)
		q.pop();
	for(int i=0;i<1000005;i++)
	for(int j=0;j<6;j++)
		checked[i][j]=false;
	checked[init][0]=true;
	q.push(begin);
	bfs();
	cout<<step<<endl;
	system("pause");
	return 0;
}

void bfs(){
	int record[10]; 
	Node tem;
	while(q.empty()==false){
		int size=q.size();		
		//cout<<"size: "<<size<<endl;
		for(int i=0;i<size;i++){
			Node tmp=q.front();
			q.pop();
			int position=tmp.pos;
			int num=tmp.number;
			if(num==goal)
				return;			
			//Node nextNode;
			for(int j=5;j>=0;j--){
				record[j]=num%10;
				num=num/10;
			}
			//swap0
			swap(record,position-1,0);
			tem.number=getNumber(record);			
			swap(record,position-1,0);
			tem.pos=position;
			if(checked[tem.number][tem.pos-1]==false){
				q.push(tem);
				checked[tem.number][tem.pos-1]=true;
			}
			//swap1
			swap(record,position-1,5);
			tem.number=getNumber(record);
			swap(record,position-1,5);
			tem.pos=position;
			if(checked[tem.number][tem.pos-1]==false){
				q.push(tem);
				checked[tem.number][tem.pos-1]=true;
			}
			//up
			if(record[position-1]<9){
				record[position-1]++;
				tem.number=getNumber(record);
				tem.pos=position;
				if(checked[tem.number][tem.pos-1]==false){
					q.push(tem);
					checked[tem.number][tem.pos-1]=true;
				}
				record[position-1]--;
			}
			//down
			if(record[position-1]>0){
				record[position-1]--;
				tem.number=getNumber(record);
				tem.pos=position;
				if(checked[tem.number][tem.pos-1]==false){
					q.push(tem);
					checked[tem.number][tem.pos-1]=true;
				}
				record[position-1]++;
			}
			//left
			/*if(position>1){
				position--;
				tem.number=tmp.number;
				tem.pos=position;
				if(checked[tem.number][tem.pos-1]==false){
					q.push(tem);
					checked[tem.number][tem.pos-1]=true;
				}
				position++;
			}*/
			//right
			if(position<6){
				position++;
				tem.number=tmp.number;
				tem.pos=position;
				if(checked[tem.number][tem.pos-1]==false){
					q.push(tem);
					checked[tem.number][tem.pos-1]=true;
				}
				position--;
			}//end if
		}//end for loop
		step++;
	}//end while loop
	//cout<<"can not find the solution"<<endl;
	return;
}

void swap(int record[],int pos1,int pos2){
	int tmp;
	tmp=record[pos1];
	record[pos1]=record[pos2];
	record[pos2]=tmp;
	return;
}

int getNumber(int record[]){
	int sum=0;
	for(int i=0;i<6;i++){
		sum*=10;
		sum+=record[i];
	}
	return sum;
}
