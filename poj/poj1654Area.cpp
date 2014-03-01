#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

const int dir_x[]={0,-1,0,1,-1,0,1,-1,0,1};
const int dir_y[]={0,-1,-1,-1,0,0,0,1,1,1};
struct Point{
	double x,y;
};
Point p1,p2,current;
double dbl(Point a,Point b);

int main(){
	int t,len;
	double area;
	char str[1000005];
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		len=strlen(str);
		//first=false;
		area=0;
		current.x=0; current.y=0;
		p1=current;	
		int last=-1;	
		for(int i=0;i<len-1;i++){
			int direction=str[i]-'0';
			if(last!=direction){
				p2=current;
				area+=dbl(p1,p2);
				p1=p2;
			}
			current.x+=dir_x[direction];
			current.y+=dir_y[direction];
			last=direction;
		}
		if(area<0)
			area=-area;
		long long goal=(long long)area;
		if(goal%2==0)
			cout<<goal/2<<endl;
		else
			cout<<goal/2<<".5"<<endl;
		//cout<<area/2<<endl;
	}
	system("pause");
	return 0;
}

double dbl(Point a,Point b){
	return (a.x)*(b.y)-(b.x)*(a.y);
}
