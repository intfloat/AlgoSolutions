#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
using namespace std;

long long dp[32][32];
int pre[32];
int score[32];
int n;

// Tree Dynamic Programming
long long solve(int l, int r){
	if(l > r){
		if(l>=0 && r>=0)
			dp[l][r] = 1;
		return 1;
	}
	if(dp[l][r] == -1){
		if(l == r)
			dp[l][r] = score[l];
		else{
			for(int i=l; i<=r; i++){
				long long tmp = solve(l, i-1)*solve(i+1, r)+score[i];	
				dp[l][r] = max(dp[l][r], tmp);				
			}
		}
	}	
	return dp[l][r];
}

void f(int l, int r){
	if(l > r)
		return;
	if(l == r){
		cout<<l+1<<" ";
		return;
	}
	for(int i=l; i<=r; i++){
		long long t1;
		if(i-1 < 0)
			t1 = 1;
		else t1 = dp[l][i-1];
		long long tmp = t1*dp[i+1][r]+score[i];
		if(tmp == dp[l][r]){
			cout<<i+1<<" ";
			if((i-1) >= l)
				f(l, i-1);
			if(r >= (i+1))
				f(i+1, r);
			break;
		}
	}
	return;
}


int main(){	
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>score[i];
	long long res = 0;
	for(int i=0; i<32; i++)
	for(int j=0; j<32; j++)
		dp[i][j] = -1;
		
	solve(0, n-1);
	
	res = dp[0][n-1];
	cout<<res<<endl;
	f(0, n-1);
	cout<<endl;
	system("pause");
	return 0;
}
