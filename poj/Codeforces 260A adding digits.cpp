/*
codeforces 260A
ÿһ�ζ���Ҫ��֤�ܹ����������Ե�һ��������ܽ����򲻴��ڣ� 
 �����һ���ܽ��У��������0�Ϳ����ˡ� 
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
