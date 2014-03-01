#include<cstdio>
#include<iostream>
using namespace std;

int m, n;
int s[150];
int s_sum=0;
long long f[11][2048];

void read_in();
void creat_s();
long long dp();

int main() {
	read_in();
	while (!((m == 0) && (n == 0))) {
		creat_s();
		cout<<"test: "<<s_sum<<endl;
		long long result = dp();
		printf("%I64d\n",result);
		read_in();
	}
	return 0;
}
void read_in() {
	scanf("%d%d", &m, &n);
	if (n > m) {
		int temp = m;
		m = n;
		n = temp;
	}

	for(int i=0;i<150;i++)s[i]=0;
	s_sum=0;
	for(int i=0;i<11;i++)
		for(int j=0;j<2080;j++)
			f[i][j]=0;
}
void dfs(int x, int data,int num_of_0) {
	if (x == m) {
		//0的个数为奇数不符合要求 
		if(num_of_0%2==1) return;
		s[s_sum++] = data;
		return;
	}
	if (num_of_0%2==1) {
		dfs(x + 1, data,num_of_0+1);
	} else {
		//填充0的情形 
		dfs(x + 1, data,num_of_0+1);
		//填充1的情形 
		dfs(x + 1, data | (0X1 << x),num_of_0);
	}
}
void creat_s() {
	dfs(0,0,0);
}
long long dp(){
	int sum=1;
	for(int i=0;i<m;i++) sum*=2;

	//dp初始化的过程 
	for(int i=0;i<s_sum;i++){
		f[0][s[i]]=1;
	}
	//dp的核心过程 
	for(int i=1;i<n;i++){
		for(int x=0;x<s_sum;x++){
			for(int y=0;y<sum;y++){
				//不可行的方案 
				if(f[i-1][y]==0) continue;
				//与上级矛盾的方案 
				if(((y)&(~s[x]))!=0)continue;
				//减去非向下突出的情形 
				f[i][s[x]-y]+=f[i-1][y];
			}
		}
	}
	return f[n-1][0];
}
