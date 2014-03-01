#include<iostream>
#include<iomanip>
using namespace std;

int dfs(int x,int number,int zero);
double dp();
int init();

//记录所有可能的情况 
int s[1000],sum;
//记录每行所有可能的取值 
double num[12][2050];
int m,n;
 
int main(){	
	while(cin>>m>>n&&m>0&&n>0){
		init(); 
	    dfs(0,0,0);
	    //cout<<"test: "<<sum<<endl;
		double goal=dp();
		cout<<fixed<<setprecision(0)<<goal<<endl;
	}
	return 0;
} 

int init(){
	if (n > m) {
		int temp = m;
		m = n;
		n = temp;
	}
	for(int i=0;i<1000;i++)
		s[i]=0;
	for(int i=0;i<12;i++)
	for(int j=0;j<2050;j++)
		num[i][j]=0;
	sum=0;
	return 0;
}

double dp(){
	//面积为奇数不可能覆盖 
	if((n*m)%2==1)
		return 0;
	int tmp=1;
	//for(int i=0;i<12;i++)
	//for(int j=0;j<2050;j++)
	//	num[i][j]=0;
	//总的情况数目 
	for(int i=0;i<m;i++)
		tmp*=2;
	for(int i=0;i<sum;i++)
		num[0][s[i]]=1;
	for(int i=1;i<n;i++)
	for(int j=0;j<sum;j++)
	for(int k=0;k<tmp;k++){
		if(num[i-1][k]==0)
			continue;
		//与上一层发生了不吻合的矛盾 	
		if((k&(~s[j]))!=0)
			continue;
		num[i][s[j]-k]+=num[i-1][k]; 
	} 
	//最后一行填充零的数目即答案 
	return num[n-1][0];
}

int dfs(int x,int number,int zero){
	//边界情况 
	if(x==m){
		if(zero%2==1)
			return 0;
		s[sum++]=number; 
		return 0;
	}
	else if(x<m){
		if(zero%2==0){
			//取0的情形 
			dfs(x+1,number,zero+1);
			//取1的情形 
			dfs(x+1,number|(1<<x),zero);
		}
		else if(zero%2==1)
			//下一位必须取值0 
			dfs(x+1,number,zero+1); 
	}
	return 0; 
}
