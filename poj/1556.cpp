//最悲催的事情莫过于程序写完了，却发现思路一开始就错了 …… 
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

const int MAXIMUM=999999;

struct Wall{
	double x;
	double y[5];
	double minDis[5];
};
Wall wall[20];

double dis(double x1,double y1,double x2,double y2);

int main(){
	int t;
		
	while(cin>>t&&t!=-1){
		for(int i=0;i<t;i++){
			cin>>wall[i].x;
			for(int j=0;j<4;j++)
				cin>>wall[i].y[j];
			for(int j=0;j<5;j++)			
				wall[i].minDis[j]=MAXIMUM;
		}
		if(t==0){
			cout<<"10.00"<<endl;
			continue;
		}
		for(int i=0;i<t;i++){
			for(int j=0;j<4;j++){
				if(i==0){
					wall[i].minDis[j]=dis(0,5,wall[i].x,wall[i].y[j]);
					continue;
				}
				for(int k=0;k<4;k++){
					wall[i].minDis[j]=min(wall[i].minDis[j],
								wall[i-1].minDis[k]+dis(wall[i-1].x,wall[i-1].y[k],wall[i].x,wall[i].y[j]));
				}
			}//end inner for loop
		}//end external for loop
		double goal=MAXIMUM;
		for(int i=0;i<4;i++){
			goal=min(goal,dis(10,5,wall[t-1].x,wall[t-1].y[i]));
		}
		cout<<fixed<<setprecision(2)<<goal<<endl;
	}
	system("pause");
	return 0;
}

//calculate distance between two points
double dis(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
