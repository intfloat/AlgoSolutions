#include<iostream>
#include<stdlib.h>
#include<memory.h>
using namespace std;
bool Find(int Len,int nSticks,int left);
int compare(const void *elem1,const void *elem2){
	return *(int *)elem2-*(int *)elem1;
}
int n,L[200];
bool used[200]; 
int main(){
	int sum,Max;
	for(;;){
		sum=0;
		cin>>n;
		if(n==0)
			break;
		memset(used,false,n);
		for(int i=0;i<n;i++){
			cin>>L[i];
			sum+=L[i];
		}
		qsort(L,n,sizeof(int),compare);
		Max=L[0];		
		for(int i=Max;i<=sum;i++){
			if(sum%i!=0)
				continue;			
			if(i>sum/2){
				cout<<sum<<endl;
				break;
			}
			if(Find(i,0,0)==true){
				cout<<i<<endl;
				break;
			}			
		}
	}
	return 0;
}
bool Find(int Len,int nSticks,int left){//nSticks¡À¨ª¨º?¨°??-¨®?1y¦Ì???1¡Â¨ºy?? 
	if(nSticks==n&&left==0)
		return true;
	if(left==0) left=Len;
	for(int i=0;i<n;i++){
		if(used[i]==true||L[i]>left)
			continue;
		used[i]=true;
		if(Find(Len,nSticks+1,left-L[i])==true)
			return true;
		used[i]=false;
		if(L[i]==left||left==Len) break;
	}
	return false;		
}
