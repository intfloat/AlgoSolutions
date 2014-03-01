#include<iostream>
#include<stdlib.h>
using namespace std;

bool binary_search(int goal,int l,int r);       
int cmp(const void*ele1, const void*ele2){
	return (*(int *)ele1)-(*(int *)ele2);
}
int* num;
int main(){
	int sum,n;
	bool find;
	cin>>n>>sum;
	num=new int[n+5];
	for(int i=0;i<n;i++)
		cin>>num[i];
	qsort(num,n,sizeof(int),cmp);
	find=false;
	for(int i=0;i<n;i++){
		if(num[i]>sum/2)
			break;
		if(binary_search(sum-num[i],i+1,n-1)==true){
			find=true;
			break;
		}
	}
	if(find==true)
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	system("pause");
	return 0;
}

//进行二分查找 
bool binary_search(int goal,int l,int r){
	int middle;
	while(l<=r){
		middle=(l+r)/2;
		if(num[middle]==goal)
			return true;
		else if(num[middle]<goal)
			l=middle+1;
		else r=middle-1;
	}
	return false;
}
