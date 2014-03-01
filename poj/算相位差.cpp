#include<iostream>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	double f,t;
	while(cin>>f>>t){
		cout<<f<<": "<<360*f*t*(1e-6)<<endl;
	}
	return 0;
}
