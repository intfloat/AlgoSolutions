#include<iostream>
#include<stdlib.h>
#define MAX 100
using namespace std;
int main(){
	int t,tmp,num[MAX];
	cin>>t;
	//for(int i=0;i<t;i++)
	//	cin>>num[t];
	for(int i=0;i<=40;i++)
		num[i]=0;
	//num[0]=1;
	for(int i=0;i<t;i++){
		cin>>tmp;		
		for(int j=40;j>=0;j--){
			if(j-tmp>=0)
				num[j]+=num[j-tmp];
		}		
		num[tmp]++;				
	}
	//if(num[tmp+tmp]<num[tmp])
	//	num[tmp+tmp]=num[tmp];
	cout<<num[40]<<endl;
	system("pause");
	return 0;
}
