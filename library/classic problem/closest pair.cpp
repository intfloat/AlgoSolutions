#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#define INF 1e10
#define SIZE 100005
using namespace std;

//����ϵ
struct node{
double x,y;
}point[SIZE];

int n;

//�ȴ�С
bool dx(node p1,node p2){
	if(p1.x != p2.x) 
		return p1.x < p2.x;
	else 
		return p1.y < p2.y;
}

//�������
double a(node a, node b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

//�ݹ�
//��ߺ��ұ߾���ֻ��1��2ʱö�ٴ�
double solve(int l,int r)
{
	if(l == r)//���=�ұߡ���������
   		return INF;
	if(l == r - 1)//����1
	   return a(point[l],point[r]);
	if(l == r - 2)//����2
	   return min(min(a(point[l],point[l+1]),a(point[l+1],point[l+2])),a(point[l],point[l+2]));
	int i,j,mid = (l+r) >> 1;//һ��
	double am = min(solve(l,mid),solve(mid+1,r));
	//��������Ƿ���Խ���
	for(i=l;i<=r;i++)
	   for(j=i+1;j<=i+5 && j<=r;j++){
		    am = min(am,a(point[i],point[j]));
   		}
	return am;
}

int main()
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
    scanf("%lf %lf",&point[i].x,&point[i].y);
   sort(point,point+n,dx);
   double ans = solve(0,n-1);
   printf("%.3lf\n",ans);
   return 0;
}
