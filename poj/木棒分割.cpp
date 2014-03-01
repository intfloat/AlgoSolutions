#include<iostream>
using namespace std;

void buildHeap(int tmp);
void siftUp(); 
void siftDown();

int heap[10005];
int heapSize;

int main(){
	int sum,n,tmp;
	int number1,number2;
	cin>>n;
	heapSize=0; sum=0;
	for(int i=0;i<n;i++){
		cin>>tmp;
		buildHeap(tmp);
	}
	for(int i=0;i<n-1;i++){
		number1=heap[0];
		heap[0]=heap[heapSize-1];
		heapSize--;
		siftDown();
		number2=heap[0];
		heap[0]=heap[heapSize-1];
		heapSize--;
		siftDown();
		sum+=number1+number2;
		//heapSize++;
		buildHeap(number1+number2);
	}
	cout<<sum<<endl;
	system("pause");
	return 0;
}

void siftDown(){
	int tmp=0;
	while(tmp<heapSize){
		int child1=2*tmp+1,child2=2*tmp+2;
		if(child1>=heapSize)
			return;
		else if(child2>=heapSize){
			if(heap[child1]>=heap[tmp])
				return;
			else{
				int tm=heap[tmp];
				heap[tmp]=heap[child1];
				heap[child1]=tm;
				return;
			}
		}
		//两个子节点都存在的情形
		if(heap[child1]>=heap[tmp]&&heap[child2]>=heap[tmp])
			return;
		else if(heap[child1]<heap[child2]){
			int tm=heap[tmp];
			heap[tmp]=heap[child1];
			heap[child1]=tm;
			tmp=child1;
			continue;
		} 
		else{
			int tm=heap[tmp];
			heap[tmp]=heap[child2];
			heap[child2]=tm;
			tmp=child2;
			continue;
		}
	}
	return;
}

void siftUp(){
	int tmp=heapSize-1;
	while(tmp>=0){
		if((tmp-1)/2<0)
			return;
		//堆调整的过程结束 
		else if(heap[(tmp-1)/2]<=heap[tmp])
			return;			
		else{
			int tm=heap[tmp];
			heap[tmp]=heap[(tmp-1)/2];
			heap[(tmp-1)/2]=tm;
			//变成父节点继续查找 
			tmp=(tmp-1)/2;
		}
	}
	return; 
} 

//建堆的过程 
void buildHeap(int tmp){
	if(heapSize==0){
		heap[0]=tmp;
		heapSize++;
		return;
	}
	heap[heapSize]=tmp;
	heapSize++;
	siftUp();
	return;
}
