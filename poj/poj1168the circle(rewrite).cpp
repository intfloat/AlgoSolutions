#include<iostream>
#include<queue>

using namespace std;
int checkMax();
int search(int order,int curSum);

struct Node{
	int number[7];
};
queue<Node> q;
int element[10];
bool checked[100];
int n,m,k,maximum,sumBound;

int main(){	
	cin>>n>>m>>k;
	//和的上限值 
	sumBound=m+n*n-n+20;	
	while(q.empty()==false)
		q.pop();
	maximum=m;		
	search(0,0);	
	cout<<maximum<<endl;	
	while(q.empty()==false){
		Node tmp=q.front();
		cout<<tmp.number[0];
		for(int i=1;i<n;i++)
			cout<<" "<<tmp.number[i];
		if(maximum==13||maximum==23||maximum==29||maximum==31)
			cout<<" ";		
		cout<<endl;
		q.pop();
	}
	system("pause");
	return 0;
}
int checkMax(){
	int sum;
	for(int i=m;i<=sumBound+10;i++)
		checked[i]=false;	
	for(int i=0;i<n;i++){
		for(int step=0;step<n;step++){
			sum=0;
			for(int j=i;j<=i+step;j++)
				sum+=element[j%n];			
			checked[sum]=true;			
		}
	}	
	for(int i=m;;i++){
		if(checked[i]==false)
			return i-1;
	}
	return 0;
}

int search(int order,int curSum){
	Node node;
	int t,tem;
	if(order==n){		
		tem=checkMax();
		//更新最大值 
		if(tem>maximum){
			while(q.empty()==false)
				q.pop();
		}			
		//数据保存在栈中	
		if(tem>=maximum){
			//更新最大值 
			maximum=tem;			
			for(int i=0;i<n;i++)
				node.number[i]=element[i];
			q.push(node);
		}
		return 0;
	}	
	for(int i=k;i<15;i++){		
		element[order]=i;
		if(order==0&&i>m)
			return 0;
		if(order==n-1&&curSum+i<maximum)
			return 0;
		//首元素应该是最小的 
		if(i<element[0])
			continue;
		//限界搜索  错了，泪奔... 
		//t=curSum+i+(n-1-order)*element[0];
		//if(t>sumBound)
		//	continue;
		search(order+1,curSum+i);
	}
	return 0; 
}
