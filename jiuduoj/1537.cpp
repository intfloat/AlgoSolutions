// dynamic programming should work
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
#include <cassert>
 
using namespace std;
 
const int MAX_N = 1005;
int dp[MAX_N][MAX_N * 2];
 
int main() {
    int n, k, arr[MAX_N];
    while (scanf("%d%d", &n, &k) != EOF) {
        k <<= 1;
        for (int i = 0; i < n; ++i) scanf("%d", arr + i);
        for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < 2*MAX_N; ++j)
            dp[i][j] = -(INT_MAX / 2);
        for (int i = 0; i < MAX_N; ++i) dp[i][0] = 0;
        dp[1][1] = -arr[0];
        dp[1][0] = 0;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= min(k, i); ++j) {
                if (j&1) {
                    dp[i][j] = max(dp[i - 1][j - 1] - arr[i - 1], dp[i - 1][j]);
                }
                else {
                    dp[i][j] = max(dp[i - 1][j - 1] + arr[i - 1], dp[i - 1][j]);
                }
                // cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        int res = 0;
        for (int i = 2; i <= k; i+=2) res = max(res, dp[n][i]);
        printf("%d\n", res);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1537
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:130 ms
    Memory:9408 kb
****************************************************************/