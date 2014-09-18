/**
* Two important things:
* 1. dynamic programming without constraints can be completed in linear time
* 2. use of inclusion exclusion principle
**/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int MAX_S = 100005;
int val[4], tot;
long long dp[MAX_S];

long long get(int i) {
	if (i < 0) return 0;
	else return dp[i];
}

int main() {
	for (int i = 0; i < 4; ++i) scanf("%d", val + i);
	scanf("%d", &tot);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < 4; ++i) {
    	for (int j = val[i]; j < MAX_S; ++j)
    		dp[j] += dp[j - val[i]];
    }
    while (tot--) {
    	long long cnt[4], target;
    	for (int i = 0; i < 4; ++i) scanf("%lld", cnt + i);
        scanf("%lld", &target);
        long long res = dp[target];
        for (int i = 0; i < 4; ++i) res -= get(target - (cnt[i] + 1) * val[i]);
        for (int i = 0; i < 4; ++i)
        	for (int j = i + 1; j < 4; ++j)
        		res += get(target - (cnt[i] + 1) * val[i] - (cnt[j] + 1) * val[j]);
        for (int i = 0; i < 4; ++i)
        	for (int j = i + 1; j < 4; ++j)
        		for (int k = j + 1; k < 4; ++k)
        			res -= get(target - (cnt[i] + 1) * val[i] - (cnt[j] + 1) * val[j]
        				              - (cnt[k] + 1) * val[k]);
        printf("%lld\n", res);
    }
	return 0;
} 
