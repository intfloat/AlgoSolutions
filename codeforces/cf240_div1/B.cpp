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

const int MOD = 1000000007;
int main(){
	int n, k;
	cin>>n>>k;
	long long dp[2005][2];	
	memset(dp, 0, sizeof(dp));
	for (int i=1; i<=k; i++) {
		for (int num=1; num<=n; num++) {
			if (i==1) dp[num][1] = 1;
			else {
				dp[num][1] = 0;
				for (int j=1; j*num<=n; j++) {
					dp[num][1] += dp[j*num][0];
					dp[num][1] %= MOD;
				}
			}
		}
		for (int j=0; j<2005; j++) dp[j][0] = dp[j][1];
	}
	long long res = 0;
	for (int i=1; i<=n; i++) res = (res+dp[i][0])%MOD;
	cout<<res<<endl;
	return 0;
}
