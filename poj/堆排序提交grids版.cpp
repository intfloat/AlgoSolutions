//堆排序

#include<iostream>
#define MAX 1000
using namespace std;

int sift_down(int num[MAX],int i,int Size);
int swap(int num[MAX],int i,int j);
int BuildMaxHeap(int num[MAX],int Size);

int len;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i=0,num[MAX],CurrentSize;
	int n;
	cin>>n;
	while(cin>>num[i])
		i++;
	len=i;
	CurrentSize=len;
	//建立最大值堆 
	BuildMaxHeap(num,len);
	//cout<<"堆排序哦亲~"<<endl;	
	while(CurrentSize>1){
		//将堆顶元素与最末尾的元素交换 
		swap(num,0,CurrentSize-1);
		CurrentSize--;
		//向下筛选调整堆 
		sift_down(num,0,CurrentSize);
		//输出每一次堆调整后的结果
		/*for(i=0;i<len;i++)
			cout<<num[i]<<" ";
		cout<<endl; */
	}
	for(i=0;i<len;i++)
		cout<<num[i]<<endl;
	//cout<<endl; 
	return 0;
} 
int sift_down(int num[MAX],int i,int Size){
	int j=2*i+1;
	//i应当为非叶结点 
	while(i<Size&&j<Size){
		//右子结点的值大于左子结点的值 
		if(j+1<Size&&num[j+1]>num[j])
			j++;
		if(num[i]<num[j]){
			swap(num,i,j);
			i=j;
			j=2*i+1;
		}
		else
			return 0;
	}
	return 0;
}

int BuildMaxHeap(int num[MAX],int Size){
	int bottom=(Size-2)/2;
	for(int i=bottom;i>=0;i--){
		//筛法建堆的过程 
		sift_down(num,i,Size);
	}
	return 0;
}

//元素交换的过程 
int swap(int num[MAX],int i,int j){
	int tmp;
	tmp=num[j];
	num[j]=num[i];
	num[i]=tmp;
	return 0;
}
