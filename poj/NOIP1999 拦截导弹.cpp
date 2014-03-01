#include<iostream>
#include<string.h>
using namespace std;

struct Node{
	int h;
	int parent;
	int number;
};
Node node[1005];

int main(){
	int n,size,goal;
	bool check[1005];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>node[i].h;
	size=n;
	int counter=0;
	while(size>0){
		counter++;
		memset(check,false,size);
		for(int i=0;i<size;i++){
			node[i].number=1;
			node[i].parent=-1;
		}
		node[0].number=1;
		for(int i=1;i<size;i++){
			for(int j=i-1;j>=0;j--){
				if( (node[i].h<=node[j].h) 
					&& (node[i].number<node[j].number+1) ){						
					node[i].number=node[j].number+1;
					node[i].parent=j;
				}
			}
		}
		int maximum=-1;
		for(int i=0;i<size;i++){
			if(node[i].number>maximum){
				maximum=node[i].number;
				goal=i;
			}
		}
		if(counter==1)
			cout<<maximum<<" ";
		int ptr=goal;
		while(node[ptr].parent!=-1){
			check[ptr]=true;
			ptr=node[ptr].parent;
		}
		check[ptr]=true;
		//size=size-maximum;
		int k=0;
		for(int i=0;i<size;i++){
			if(check[i]==false){
				node[k++]=node[i];
			}
		}
		size=size-maximum;
	}
	cout<<counter<<endl;
	system("pause");
	return 0;
}
