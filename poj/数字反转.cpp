#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char num[100];
	int len;
	bool first;
	cin>>num;
	len=strlen(num);
	if(num[0]=='-')
		cout<<'-';
	first=true;
	for(int i=len-1;i>=0;i--){
		if(num[i]=='-')
			break;
		else if(num[i]!='0'||first==false){
			cout<<num[i];
			first=false;
		}
	}
	cout<<endl;
	system("pause");
	return 0;
}
