#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

const double PI=3.1415926535;
struct Point{
	double x,y;
};
Point point[205];
double beta(int k);

int main(){
	double k,h;
	int n;
	double angle,maximum,minimum,answer;
	cin>>k>>h>>n;
	for(int i=0;i<n;i++)
		cin>>point[i].x>>point[i].y;
	angle=0;
	maximum=0;
	minimum=0;
	point[n]=point[0];
	for(int i=0;i<n;i++){
		angle+=beta(i);
		maximum=max(maximum,angle);
		minimum=min(minimum,angle);
		//cout<<"here: "<<angle<<endl;
	}
	
	angle=max(angle,-angle);
	if(fabs(angle-2*PI)<1e-4)
		answer=2*PI;
	else{
		answer=maximum-minimum;
		if(answer>2*PI)
			answer=2*PI;
	}
	//cout<<"angle: "<<answer<<endl;
	answer*=k*h;	
	cout<<fixed<<setprecision(2)<<answer<<endl;
	system("pause");
	return 0;
}

double beta(int k){
	//double result=(point[k].x)*(point[k+1].y)-(point[k+1].x)*(point[k].y);	
	double a=sqrt(point[k].x*point[k].x+point[k].y*point[k].y);	
	double deg1=acos(point[k].x/a);
	if(point[k].y<0)
		deg1=2*PI-deg1;
	double b=sqrt(point[k+1].x*point[k+1].x+point[k+1].y*point[k+1].y);
	double deg2=acos(point[k+1].x/b);
	if(point[k+1].y<0)
		deg2=2*PI-deg2;
	double ans=deg2-deg1;
	//cout<<"ee: "<<ans<<" "<<a<<" "<<" "<<b<<" "<<result<<endl;
	if(ans>=PI)
		ans-=2*PI;
	else if(ans<=-PI)
		ans+=2*PI;
	return ans;
}
