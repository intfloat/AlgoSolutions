#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int binarySearch(int i);
int cmp(const void*elem1, const void*elem2){
	return (*(int *)elem1)-(*(int *)elem2);
}

int n,length,current;
bool checked[100001];
int height[100001];

int main(){
	int counter;
	int order;
	scanf("%d",&n);
	scanf("%d",&length);
	for(int i=0;i<n;i++){
		scanf("%d",&height[i]);
		checked[i]=false;
	}
	qsort(height,n,sizeof(int),cmp);
	//for(int i=0;i<n;i++)
	//	cout<<"i: "<<height[i]<<endl;
	counter=0; current=n-1;
	for(int i=0;i<n;i++){
		if(checked[i]==true)
			continue;		
		checked[i]=true;		
		order=binarySearch(i);
		if(order==-1){
			counter=n-counter;
			break;
		}
		else{
			current=order-1;
			checked[order]=true;
			counter++;
		}
	}
	printf("%d\n",counter);
	system("pause");
	return 0;
}

int binarySearch(int i){
	//int l=i+1,r=n-1;
	int goal=length-height[i];
	for(int j=current;j>i;j--){
		if(checked[j]==false&&height[j]<=goal)
			return j;
	}
	return -1;	
}
