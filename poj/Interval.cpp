#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

//存储区间的结构体 
struct Interval{
	int a,b;
};
Interval interval[50005],tmp;

//qsort()所调用的基本函数 
/*int cmp(Interval* p, Interval* q){
	//Interval *p=(Interval *)elem1,*q=(Interval *)elem2;
	if((p->b)!=(q->b))
		return (p->b)-(q->b);
	else return (p->a)-(q->a);
} */
void mySort(int left,int right);
int partition(int left,int right);

int main(){
	int n,tmp_a,tmp_b;	
	stack<Interval> s,goal;
	scanf("%d",&n);
	//cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d%d",&interval[i].a,&interval[i].b);
		//cin>>interval[i].a>>interval[i].b;
	mySort(0,n-1);
	//qsort(interval,n,sizeof(Interval),cmp);
	//栈清空 
	while(s.empty()==false)
		s.pop();
	while(s.empty()==false)
		goal.pop();
	//贪心算法的核心部分 
	for(int i=0;i<n;i++){
		while(s.empty()==false){
			tmp=s.top();
			tmp_a=tmp.a;  tmp_b=tmp.b;
			if(tmp_b<interval[i].a){
				s.push(interval[i]);
				break;
			}
			else if(tmp_b>=interval[i].a&&tmp_a<=interval[i].a){
				s.pop();
				tmp.b=interval[i].b;
				s.push(tmp);
				break;
			}
			else if(tmp_b>=interval[i].a&&tmp_a>interval[i].a){
				s.pop();
				continue;
			}
		}
		if(s.empty()==true)
			s.push(interval[i]);
	} 
	while(s.empty()==false){
		goal.push(s.top());
		s.pop();
	}
	while(goal.empty()==false){
		tmp=goal.top();
		printf("%d %d\n",tmp.a,tmp.b);
		//cout<<tmp.a<<" "<<tmp.b<<endl;
		goal.pop();
	}
	system("pause");
	return 0;
}

//对区间进行分割 
int partition(int left,int right){
	int pivot=l,l=left,r=right;
	Interval tmp=interval[pivot];
	while(l<r){
		while(l<r&&interval[l].b<tmp.b)
			l++;
		if(l<r)
			interval[r--]=interval[l];
		while(l<r&&interval[r].b>tmp.b)
			r--;
		if(l<r)
			interval[l++]=interval[r];
	}
	interval[l]=tmp;
	return l;
}

void mySort(int left,int right){
	/*int pivot=right;
	if(right-left<1)
		return;
	pivot=partition(left,right);
	mySort(left,pivot-1);
	mySort(pivot+1,right);
	return;*/
}
