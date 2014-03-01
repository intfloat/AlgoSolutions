#include<iostream>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char tmp[100];
	int counter=0;
	while(cin>>tmp){
		counter++;
		if(counter%2==0)
			cout<<tmp<<endl;
	}
	return 0;
}
