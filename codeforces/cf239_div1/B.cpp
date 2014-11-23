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

const int SIZE = 1005;
const int ODD = 1;
const int EVEN = 0;
const int MOD = 1000000007;
long long dp[SIZE][SIZE];
long long res[SIZE][2];
int main(){
	int n, p[SIZE];
	cin>>n;
	for(int i=1; i<=n; i++) cin>>p[i];
	res[1][ODD] = 0;
	res[1][EVEN] = 1;
	res[2][ODD] = 2;
	dp[1][1] = 0;
	for(int i=2; i<=n; i++){
		dp[i][i] = 0;
		for(int j=i-1; j>=1; j--){
			dp[j][i] = (1+dp[p[j]][j]+1+dp[j+1][i])%MOD;
		}
		res[i][ODD] = (res[i-1][EVEN]+1)%MOD;
		if(p[i]==i){
			res[i][EVEN] = (res[i][ODD]+1)%MOD;
		}
		else{
			res[i][EVEN] = (res[i][ODD]+1+dp[p[i]][i])%MOD;
		}
	}
	res[n+1][ODD] = (res[n][EVEN]+1)%MOD;
	cout<<res[n+1][ODD]<<endl;
	return 0;
}
