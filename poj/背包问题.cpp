#include<iostream>
using namespace std;
int main(){
	int bag[1005],value[100000];
	int weight,n,tmp;
	cin>>weight;
	cin>>n;
	//bag=new int[n+1];
	//value=new int[weight+1];
	for(int i=0;i<n;i++)
		value[i]=0;
	for(int i=0;i<n;i++)
		cin>>bag[i];
	for(int i=0;i<n;i++){
		cin>>tmp;
		//必须从高到低进行搜索 
		for(int j=weight;j>=1;j--){
			if(j-bag[i]<0)
				continue;
			else if((value[j-bag[i]]+tmp)<=value[j])
				continue;
			else
				value[j]=value[j-bag[i]]+tmp;
		}
	}
	cout<<value[weight]<<endl;
	//for(int )
	system("pause");
	return 0;
}
