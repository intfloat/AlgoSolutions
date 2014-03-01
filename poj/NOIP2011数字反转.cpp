#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int len,end;
	char str[1001];
	bool fir;
	cin>>str;
	len=strlen(str);
	end=0;
	if(str[0]=='-'){
		cout<<"-";
		end=1;
	}
	fir=false;
	for(int i=len-1;i>=end;i--){
		if(str[i]=='0'&&fir==false)
			continue;
		else{
			cout<<str[i];
			fir=true;
		}
	}
	cout<<endl;
	system("pause");
	return 0;
}
