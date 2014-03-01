#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

//�洢����Ľṹ�� 
struct Interval{
	int a,b;
};
Interval interval[50005],tmp;

//qsort()�����õĻ������� 
int cmp(const void*elem1, const void *elem2){
	Interval *p=(Interval *)elem1,*q=(Interval *)elem2;
	if((p->b)!=(q->b))
		return (p->b)-(q->b);
	else return (p->a)-(q->a);
} 

int main(){
	int n,tmp_a,tmp_b;	
	stack<Interval> s,goal;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>interval[i].a>>interval[i].b;
	qsort(interval,n,sizeof(Interval),cmp);
	//ջ��� 
	while(s.empty()==false)
		s.pop();
	while(s.empty()==false)
		goal.pop();
	//̰���㷨�ĺ��Ĳ��� 
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
		cout<<tmp.a<<" "<<tmp.b<<endl;
		goal.pop();
	}
	return 0;
}
