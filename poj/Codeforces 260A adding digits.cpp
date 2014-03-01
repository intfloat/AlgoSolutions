/*
codeforces 260A
每一次都需要保证能够整除，所以第一步如果不能进行则不存在， 
 如果第一步能进行，后面简单填0就可以了。 
*/
#include<iostream>
#include<algorithm>

using namespace std;
int main(){
	int a,b,n;
	bool flag=false;
	cin>>a>>b>>n;
	for(int i=0;i<=9;i++){
		int tmp=a*10+i;
		if((tmp%b) == 0){
			flag=true;
			cout<<tmp;
			for(int j=0;j<(n-1);j++)
				cout<<0;
			cout<<endl;
			break;
		}
	}
	if(flag==false)
		cout<<-1<<endl;	
	//system("pause");
	return 0;
}
