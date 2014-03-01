#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int Initial(int n);
int Index(char goal[30],int n);

char currency[45][30];
double money[45][45];
int main(){
	int n,m,sou,des;
	bool find;
	char source[30],desti[30];
	double rate,tmp;
	int count=0;
	while(cin>>n&&n){
		for(int i=0;i<n;i++)
			cin>>currency[i];
		Initial(n);
		find=false;
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>source>>rate>>desti;
			sou=Index(source,n);
			des=Index(desti,n);
			money[sou][des]=rate;		
		}
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		for(int k=0;k<n;k++){		
			tmp=money[j][i]*money[i][k];		
			if(tmp>money[j][k])
				money[j][k]=tmp;			
		}
		for(int i=0;i<n;i++){
			if(money[i][i]>1.0)
				find=true;
		}
		if(find==true)
			cout<<"Case "<<++count<<": Yes"<<endl;
		else cout<<"Case "<<++count<<": No"<<endl;
	}	
	return 0;
}

int Index(char goal[30],int n){
	for(int i=0;i<n;i++){
		if(strcmp(currency[i],goal)==0)
			return i;
	}
	return 0;
}

int Initial(int n){
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		money[i][j]=0;
	return 0;
}
