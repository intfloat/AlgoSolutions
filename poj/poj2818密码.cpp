//¼òÖ±±äÌ¬£¬¾ÓÈ»²»ÈÃÎÒ¹ý£¡£¡£¡ÎØÎØÎØÎØÎØÎØÎØÎØÎØÎØÎØ> < 
#include<iostream>
#include<cstring>
#include<stdio.h>
#define MAX 210
using namespace std;
int compute(int t);
int mycmp(int num1[MAX],int num2[MAX],int t);
int keyword[2000][MAX];
int base,order[MAX];
int main(){
	int t,n,period;
	char goal[MAX],str[MAX];
	while(cin>>t&&t){
		for(int i=0;i<t;i++){
			cin>>order[i];
			order[i]--;
			keyword[0][i]=i;		
		}		
		period=compute(t);		
		while(cin>>n&&n){
			getchar();
			cin.getline(str,MAX);
			int len=strlen(str);
			for(int k=len;k<t;k++)	
				str[k]=' ';
			str[t]='\0';
			if(n>base){
				n=(n-base)%period;
				n+=base;
			}		
			for(int j=0;j<t;j++)			
				goal[j]=str[keyword[n][j]];			
			goal[t]='\0';
			cout<<goal<<endl;
		}
	}
	system("pause");
	return 0;
}

int compute(int t){
	for(int i=1;i<2000;i++){
		for(int j=0;j<t;j++)
			keyword[i][order[j]]=keyword[i-1][j];		
		for(int j=0;j<i;j++){
			if(mycmp(keyword[j],keyword[i],t)==0){
				base=j;
				return i-j;
			}
		}
	}
	return 0;
}

int mycmp(int num1[MAX],int num2[MAX],int t){
	for(int i=0;i<t;i++){
		if(num1[i]!=num2[i])
			return -1;
	}
	return 0;
}
