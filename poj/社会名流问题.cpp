#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int *number,n;
	int x,y;
	bool find;
	scanf("%d",&n);
	number=new int[n];
	for(int i=0;i<n;i++)
		number[i]=0;
	while(1){
		scanf("%d%d",&x,&y);
		if(x==0&&y==0)
			break;
		number[x]--;
		number[y]++;
	}
	find=false;
	for(int i=0;i<n;i++){
		if(number[i]==n-1){
			cout<<i<<endl;
			find=true;
		}
	}
	if(find==false)
		cout<<"NOT FOUND"<<endl;
	system("pause");
	return 0;
}
