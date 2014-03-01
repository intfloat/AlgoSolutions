#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,m,tmp,counter[10005];
	int maxi,secmax;
	bool fir;
	while(scanf("%d%d",&n,&m)&&n&&m){
		maxi=-1; secmax=-1;
		for(int i=0;i<10005;i++)
			counter[i]=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			scanf("%d",&tmp);
			counter[tmp]++;
			if(counter[tmp]>maxi){			
				maxi=counter[tmp];
			}				
		}
		for(int i=0;i<10005;i++){
			if(counter[i]>secmax&&counter[i]!=maxi)
				secmax=counter[i];
		}
		fir=true;
		for(int i=0;i<10005;i++){
			if(counter[i]==secmax&&fir==true){
				fir=false;
				printf("%d",i);			
			}				
			else if(counter[i]==secmax&&fir==false)
				printf(" %d",i);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
