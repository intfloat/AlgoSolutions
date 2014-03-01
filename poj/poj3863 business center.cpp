#include<iostream>
using namespace std;
int main(){
	int n,m,d1,d2,number;
	int minimum=999999;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>d1>>d2;
		number=(d2*n)/(d1+d2)+1;
		int goal=(d1+d2)*number-d2*n;
		if(goal<minimum)
			minimum=goal;
	}
	cout<<minimum<<endl;	
	return 0;
}
