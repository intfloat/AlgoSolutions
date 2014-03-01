#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main(){
	string number;
	bool find_zero=false;
	cin>>number;
	int len=number.size();
	for(int i=0;i<len;i++){
		if(number[i]=='0' && find_zero==false){
			find_zero=true;			
			continue;
		}		
		else if(find_zero==false && i==len-1)
			continue;
		cout<<number[i];
	}	
	cout<<endl;
	system("pause");
	return 0;
}
