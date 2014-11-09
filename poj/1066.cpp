#include<iostream>
#include<cmath>
using namespace std;

struct TPoint{
	double x,y;
};
struct TWall{
	TPoint p[2];
};
TWall wall[50];

int count(TPoint a,TPoint b);
bool cross(TPoint a1,TPoint a2,TPoint b1,TPoint b2);
int dbl(TPoint a1,TPoint a2,TPoint b);

int n;
int main(){
	TPoint goal;
	//int tmp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>wall[i].p[0].x>>wall[i].p[0].y
		>>wall[i].p[1].x>>wall[i].p[1].y;
	}
	cin>>goal.x>>goal.y;
	int minimum=n+1;
	for(int i=0;i<n;i++)
	for(int j=0;j<2;j++){
		int tmp=count(wall[i].p[j],goal);
		if(tmp<minimum)
			minimum=tmp;
	}
	//if(minimum==n+1)
	//	minimum=0;	
	minimum++;
	if(n==0)
		minimum=1;
	cout<<"Number of doors = "<<minimum<<endl;
	system("pause");
	return 0;
} 

int count(TPoint a,TPoint b){
	int counter=0;
	for(int i=0;i<n;i++){
		if(cross(a,b,wall[i].p[0],wall[i].p[1])==true)
			counter++;
	}
	return counter;
}

bool cross(TPoint a1,TPoint a2,TPoint b1,TPoint b2){
	if(dbl(a1,a2,b1)*dbl(a1,a2,b2)<0&&dbl(b1,b2,a1)*dbl(b1,b2,a2)<0)
		return true;
	return false;
}

int dbl(TPoint a1,TPoint a2,TPoint b){
	double result=(a2.x-a1.x)*(b.y-a1.y)-(b.x-a1.x)*(a2.y-a1.y);
	if(fabs(result)<1e-6)
		return 0;
	else if(result<0)
		return -1;
	else if(result>0)
		return 1;
}

