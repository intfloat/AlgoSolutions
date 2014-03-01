//排序的代价

#include<iostream>
#include<stdlib.h>
#define MAX 9999999
using namespace std;
//用节点来记录该点是否被访问以及原来的位置
struct Node{
	//数据域 
	int original;
	//未排序时的位置坐标 
	int x;
	//是否已经发生交换的行为 
	bool visited; 
};
Node node[1000];
int n,num[1000];

//寻找下一个位置的元素 
int find(int tem);
//用于排序的比较函数 
int cmp(const void *elem1,const void *elem2){
	Node *p=(Node *)elem1,*q=(Node *)elem2;
	return (p->original)-(q->original);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int j,t,goal,tmp_mini,mini,sum,begin,count,min1,min2;
	
	while(cin>>t&&t){
		n=t;		
		mini=MAX; goal=0;
		//输入数据并进行必要的初始化工作 
		for(int i=0;i<t;i++){
			cin>>node[i].original;	
			num[i]=node[i].original;
			node[i].x=i;		
			//标记为未访问			
			node[i].visited=false;
			//寻找最小值 
			if(node[i].original<mini)
				mini=node[i].original;
		}
		//用快排来确定元素排好序后该呆的位置		
		qsort(node,t,sizeof(Node),cmp);
		for(int i=0;i<t;i++){
			//node[i].x表示原先的位置，i则表示应该呆的位置 
			tmp_mini=node[i].original; begin=node[i].x;	
			j=i; count=1;
			//初始化累加器		
			sum=node[i].original; 
			if(node[i].visited==false){
				node[i].visited=true;
				//i指示当前元素应该呆的位置 
				while(j!=begin){
					//寻找下一个呆的位置 					
					j=find(num[j]);	
					//求元素总和并对元素个数进行计数 
					sum+=node[j].original;
					count++;
					//寻找临时最小值 
					if(node[j].original<tmp_mini)
						tmp_mini=node[j].original;
					node[j].visited=true;				
				}
			}
			//在自身环内的最小代价 
			min1=sum+(count-2)*tmp_mini;
			//引入最小值后交换的代价 
			min2=sum+(count+1)*mini+tmp_mini;			
			//取两个代价中的小者加到总的代价中 
			if(min1<min2)
				goal+=min1;
			else goal+=min2;
		}
		//输出最终结果 
		cout<<goal<<endl;
	}
	return 0;
}

//寻找下一个位置 
int find(int tem){
	for(int i=0;i<n;i++){
		//由于元素互不相同，找到一个和目标关键值相同的结点即返回结果 
		if(node[i].original==tem)
			return i;
	}
	return 0;
}
