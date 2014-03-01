//找出第K小的元素

#include<iostream>
using namespace std;

int find_kthmin(int *num,int l,int r);
int Partition(int *num,int l,int r);

bool flag=false;
int kth_min,k;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i=0,*num;
	num=new int[1000];
	//输入输出部分 
	cin>>k;
	while(cin>>num[i])
		i++;
	int len=i;
	//寻找第k小的数字 
	find_kthmin(num,0,len-1);
	cout<<kth_min<<endl;
	return 0;
} 

int find_kthmin(int *num,int l,int r){
	//k为非法值的情形 
	if(k>len||k<=0||l>r){
		cout<<"can't found!"<<endl; 
		return 0;
	}
	if(flag==true)
		return 0;	
	//以最左端数字为轴值进行划分 
	int pivot=Partition(num,l,r);
	if(pivot==k-1){
		flag=true;
		kth_min=num[pivot];
		return 0;
	}
	//目标在左子数组 
	else if(pivot>k-1)
		find_kthmin(num,l,pivot-1);
	//目标在右子数组 
	else if(pivot<k-1)
		find_kthmin(num,pivot+1,r);
	return 0;
}

int Partition(int *num,int l,int r){
	//临时记录轴值 
	int tmp=num[l];
	while(l!=r){
		//先从右侧开始查找 
		while(num[r]>=tmp&&r>l)
			r--;
		if(r>l){
			num[l]=num[r];
			l++;
		}
		//再从左侧开始查找 
		while(num[l]<=tmp&&r>l)
			l++;
		if(r>l){
			num[r]=num[l];
			r--;
		}
	}
	//最后将轴值填在合适的位置 
	num[l]=tmp;
	//返回轴值所在的下标位置 
	return l;
}
