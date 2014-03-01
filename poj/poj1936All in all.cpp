#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char ch1[10000],ch2[10000];
	int len1,len2,i,j;
	while(cin>>ch1>>ch2){
		len1=strlen(ch1);
		len2=strlen(ch2);
		if(len1>len2){
			cout<<"No"<<endl;
			continue;
		}
		i=0; j=0;
		while(i<len1&&j<len2){
			while(j<len2&&ch2[j]!=ch1[i])
				j++;
			if(j>=len2)
				break;
			i++; j++;
		}
		if(i==len1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	system("pause");
	return 0;
}
