//以最左端数字为轴值的快速排序 

#include<iostream>
#define MAX 1000
using namespace std;

int Quick_sort(int num[MAX],int l,int r);
int Partition(int num[MAX],int l,int r);

int len,num[MAX];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i=0;
	while(cin>>num[i])
		i++;
	len=i;
	Quick_sort(num,0,len-1);	
	//system("pause");
	return 0;
} 

int Quick_sort(int num[MAX],int l,int r){
	if(l>=r)
		return l;
	int pivot=l;
	//轴值划分 
	pivot=Partition(num,l,r);
	//将所要求的结果输出 
	for(int i=0;i<len;i++)
		cout<<num[i]<<" ";
	cout<<endl;	
	//左半部分进行快速排序 
	Quick_sort(num,l,pivot-1);
	//右半部分进行快速排序 
	Quick_sort(num,pivot+1,r);
	return 0;
}

int Partition(int num[MAX],int l,int r) {
	int tmp=num[l];
	while(l<r){
		//由于轴值在左边，先对右侧进行扫描 
		while(num[r]>=tmp&&r>l)
			r--;
		if(r>l){
			num[l]=num[r];
			l++;
		}
		//再对左侧进行扫描 
		while(num[l]<=tmp&&r>l)
			l++;
		if(r>l){
			num[r]=num[l];
			r--;
		}
	}
	//此时左右指针均指向同一个元素 
	num[l]=tmp;
	return l;
}
