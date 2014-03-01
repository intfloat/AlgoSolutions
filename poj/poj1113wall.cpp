#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdlib.h>
using namespace std;
struct Point{
	int x,y;
};

int cmp(const void*elem1 ,const void*elem2);
void add(Point a,int k);
double dbl(Point a,Point b,Point c);

Point point[1005],q[1005];
int m;

int main(){
	int n,radius;
	double answer;
	cin>>n>>radius;
	for(int i=0;i<n;i++)
		cin>>point[i].x>>point[i].y;
	answer=0;
	qsort(point,n,sizeof(Point),cmp);
	//scan for two times
	//set lower bound
	m=0;
	for(int i=0;i<n;i++)
		add(point[i],1);
	//set new lower bound
	int m1=m;
	for(int i=n-2;i>=0;i--)
		add(point[i],m1);
	//m--;
	for(int i=0;i<m-1;i++){
		//cout<<"test: "<<q[i].x<<" "<<q[i].y<<endl;
		answer+=sqrt((q[i].x-q[i+1].x)*(q[i].x-q[i+1].x)
					+(q[i].y-q[i+1].y)*(q[i].y-q[i+1].y));
	}
	answer+=2*3.1415926*radius;
	cout<<fixed<<setprecision(0)<<answer<<endl;
	system("pause");
	return 0;
}

void add(Point a,int k){
	while(m>k&&dbl(q[m-2],q[m-1],a)<=0)
		m--;
	q[m++]=a;
}

double dbl(Point a,Point b,Point c){
	double result=(b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
	return result;
}

int cmp(const void*elem1 ,const void*elem2){
	Point *p=(Point *)elem1,*q=(Point *)elem2;
	if((p->y)==(q->y))
		return (p->x)-(q->x);
	else return (p->y)-(q->y);
}
