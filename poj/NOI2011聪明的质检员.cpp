#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
void preprocess(int weight);
struct Node{
	int l,r;
};
const int SIZE=200005;
Node node[SIZE];
int n,counter[SIZE],wei[SIZE],value[SIZE];
double total[SIZE];

int main(){
	double interval,min_dis,tmp;
	double standard;
	int left,right;
	
	cin>>n>>interval>>standard;
	double sum=0;
	int maximum=-1;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&wei[i],&value[i]);
		maximum=max(wei[i],maximum);
		sum+=value[i];
	}
	min_dis=sum*n;
	for(int i=1;i<=interval;i++){
		scanf("%d%d",&node[i].l,&node[i].r);
		//node[i].l--;  node[i].r--;
	}
	left=0; right=maximum;
	
	//进行二分查找 
	while(left<=right){
		//cout<<"left: "<<left<<" right: "<<right<<endl;
		int middle=(left+right)/2;
		//动态规划，O(n)的时间完成预处理 
		preprocess(middle);
		tmp=0;
		for(int i=1;i<=interval;i++){
			tmp+=(counter[node[i].r]-counter[node[i].l-1])*(total[node[i].r]-total[node[i].l-1]);
		}
		//所选的重量越大，检验量就会越大，毫无意义 
		if(tmp>standard)
			left=middle+1;
		else if(tmp<standard)
			right=middle-1;
		else if(tmp==standard){
			min_dis=standard;
			break;
		}
		if(fabs(tmp-standard)<fabs(min_dis-standard))
			min_dis=tmp;
		//if((tmp>=standard&&tmp<min_dis)||(tmp<standard&&tmp>min_dis))
		//	min_dis=tmp;		
		//cout<<"middle: "<<middle<<" min_dis "<<min_dis<<endl;
	}
	
	if(min_dis>standard)
		cout<<fixed<<setprecision(0)<<min_dis-standard<<endl;
	else cout<<fixed<<setprecision(0)<<standard-min_dis<<endl;
	system("pause");
	return 0;
}

void preprocess(int weight){
	counter[0]=0; total[0]=0;
	if(wei[1]>=weight){
		counter[1]=1;
		total[1]=value[1];
	}
	else{
		counter[1]=0;
		total[1]=0;
	}
	for(int i=2;i<=n;i++){
		if(wei[i]>=weight){
			counter[i]=counter[i-1]+1;
			total[i]=total[i-1]+value[i];
		}
		else{
			counter[i]=counter[i-1];
			total[i]=total[i-1];
		}
	}	
	return;
} 
