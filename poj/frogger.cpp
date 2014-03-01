//图论的变形，floyd搜索时换为另一种截然不同的判断标准 
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int Initial(int n);
double max(double i,double j);

struct Node{
	int x,y;	
};
Node node[1005];
double dis[205][205];
int main(){
	int n;	
	int count=0;
	while(cin>>n&&n){
		cout<<"Scenario #"<<++count<<endl;
		for(int i=0;i<n;i++)
			cin>>node[i].x>>node[i].y;
		Initial(n);
		//Floyd最短路径算法 
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		for(int k=0;k<n;k++){
			if(dis[j][k]>max(dis[j][i],dis[i][k]))
				dis[j][k]=max(dis[j][i],dis[i][k]);
		}
		cout<<"Frog Distance = ";
		cout<<fixed<<setprecision(3)<<dis[0][1]<<endl<<endl;
	}
	system("pause");
	return 0;
}

int Initial(int n){
	double tmp;
	for(int i=0;i<n;i++)
	for(int j=i;j<n;j++){
		tmp=(node[i].x-node[j].x)*(node[i].x-node[j].x);
		tmp+=(node[i].y-node[j].y)*(node[i].y-node[j].y);
		dis[i][j]=sqrt(tmp);
		dis[j][i]=dis[i][j];
	}
	for(int i=0;i<n;i++)
		dis[i][i]=0;
	return 0;
}

double max(double i,double j){
	if(i<j)
		return j;
	return i;
}
