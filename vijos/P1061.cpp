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

// Runtime Error T_T
int main(){	
	long long dp[5001][1001];
	long long arr[5005];
	int n, m;
	scanf("%d%d", &m, &n);
	for(int i=n-1; i>=0; i--)
		cin>>arr[i];
	for(int i=0; i<n; i++)
	for(int j=0; j<=m; j++)
		dp[i][j] = 999999999;
	for(int i=0; i<n; i++)
		dp[i][0] = 0;
		
	for(int i=0; i<n; i++)
	for(int j=1; j<=i; j++){
		if((3*j) > (i+1)){
			break;
		}
		long long tmp1 = dp[i-1][j];
		if((i+1-2*j) >= j)
			dp[i][j] = min(tmp1, 
				dp[i-2][j-1]+(arr[i]-arr[i-1])*(arr[i]-arr[i-1]));
		else
			dp[i][j] = tmp1;
	}
	
	cout<<dp[n-1][m]<<endl;
	system("pause");
	return 0;
}
