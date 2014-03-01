//计数排序

#include<iostream>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int *num,*count,*goal,n;
	//读入元素总数目 
	cin>>n;
	num=new int[n];
	goal=new int[n];
	count=new int[n];
	//输入元素 
	for(int i=0;i<n;i++)
		cin>>num[i];
	//进行计数 
	for(int i=0;i<n;i++){
		count[i]=0;
		for(int j=0;j<n;j++){
			if(num[j]<num[i])
				count[i]++;
		}		
	}
	//交换的过程
	for(int i=0;i<n;i++)
		goal[count[i]]=num[i]; 
	//输出排序结果 
	for(int i=0;i<n;i++)
		cout<<goal[i]<<" ";
	cout<<endl;
	return 0;
}
