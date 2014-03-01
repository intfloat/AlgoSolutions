//呜呜呜。。。怎么就runtime error了。。这么水的题。。。 
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
//const int SIZE=205;
int main(){
	
	int n,h,delta,maxi,secmaxi;
	int number[5005],tree[2010][2010],eat[2010][2010];
	int tmp,maxicounter;
	
	//scanf("%d%d%d",&n,&h,&delta);
	cin>>n>>h>>delta;
	for(int i=0;i<n;i++)
	for(int j=0;j<=n;j++){
		tree[i][j]=0;
		eat[i][j]=0;
	}
	int t;
	for(int i=0;i<n;i++){
		cin>>t;
		//scanf("%d",&number[i]);
		for(int j=0;j<t;j++){
			//scanf("%d",&tmp);
			cin>>tmp;
			tree[i][tmp]++;
		}
	}
	for(int i=0;i<n;i++){
		eat[i][h]=tree[i][h];
		for(int j=h-1;j>h-delta;j--){
			if(j<0)
				break;			
			eat[i][j]=eat[i][j+1]+tree[i][j];
		}
	}
	
	for(int hei=h-delta;hei>=0;hei--){
		if(hei<0)
			break;
		maxi=0; secmaxi=0;
		maxicounter=0; 
		//寻找最大值和次大值以优化执行效率 
		for(int i=0;i<n;i++){
			if(eat[i][hei+delta]>maxi){
				maxi=eat[i][hei+delta];
				maxicounter=1;
			}
			else if(eat[i][hei+delta]==maxi){
				maxicounter++;
			}
			else if(eat[i][hei+delta]>secmaxi&&eat[i][hei+delta]<maxi)
				secmaxi=eat[i][hei+delta];
		}
		if(maxicounter>1)
			secmaxi=maxi;
		//动态规划基本思想 
		for(int i=0;i<n;i++){
			if(eat[i][hei+delta]==maxi)
				eat[i][hei]=max(eat[i][hei+1],secmaxi)+tree[i][hei];
			else eat[i][hei]=max(eat[i][hei+1],maxi)+tree[i][hei];
		}
	}
	int maximum=0;
	for(int i=0;i<n;i++){
		if(eat[i][0]>maximum)
			maximum=eat[i][0];
	}	
	cout<<maximum<<endl;
	system("pause");
	return 0;
}
