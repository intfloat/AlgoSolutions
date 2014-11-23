#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string colors,instr;
	int len,pos;
	cin>>colors>>instr;
	len=colors.size();
	pos=1;
	
	for(int i=0;i<instr.size();i++){
		if(instr[i]==colors[pos-1])
			pos++;
	}
	cout<<pos<<endl;
	return 0;
}
