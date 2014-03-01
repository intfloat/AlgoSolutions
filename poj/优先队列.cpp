#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

void extractMin();
void addElement(int tmp);
void buildHeap(int tmp);

int heapSize,heap[50000];

int main(){
	int n,tmp,number;
	char command[20];
	scanf("%d",&n);
	heapSize=0;
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);		
		buildHeap(tmp);
	}
	scanf("%d",&number);
	for(int i=0;i<number;i++){
		scanf("%s",command);
		//cout<<"size: "<<heapSize<<endl;
		//cout<<"test: "<<heap[0]<<endl;
		if(strcmp(command,"ADD")==0){
			scanf("%d",&tmp);
			addElement(tmp);
		}
		else if(strcmp(command,"EXTRACT-MIN")==0)
			extractMin();		
	}
	system("pause");
	return 0;
}

void extractMin(){
	if(heapSize==0){
		printf("NULL\n");
		return;
	}
	heapSize--;
	printf("%d\n",heap[0]);
	heap[0]=heap[heapSize];
	//对堆进行相应的调整
	int position=0,tm;
	int number1,number2;
	while((position*2+1)<heapSize){
		//cout<<"zhong me le?"<<endl;
		number1=heap[position*2+1];
		if((position*2+2)<heapSize){
			number2=heap[position*2+2];
			if(number1>=heap[position]&&number2>=heap[position])
				break;
			else if(number1<number2){
				tm=heap[position];
				heap[position]=heap[position*2+1];
				heap[position*2+1]=tm;
				position=position*2+1;
			}
			else{
				tm=heap[position];
				heap[position]=heap[position*2+2];
				heap[position*2+2]=tm;
				position=position*2+2;
			}
		}
		else if((position*2+2)>=heapSize&&heap[position]>heap[position*2+1]){
			tm=heap[position];
			heap[position]=heap[position*2+1];
			heap[position*2+1]=tm;
			position=position*2+1;
		}
		else
			break;
	} 
	return;
} 

//添加元素 
void addElement(int tmp){
	buildHeap(tmp);
	return;
} 

//通过筛法建堆 
void buildHeap(int tmp){
	heap[heapSize]=tmp;
	int position=heapSize;
	while(position>0&&heap[(position-1)/2]>heap[position]){
		int tm=heap[position];
		heap[position]=heap[(position-1)/2];
		heap[(position-1)/2]=tm;
		position=(position-1)/2;
	}
	heapSize++;
	return;
}
