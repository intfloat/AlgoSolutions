/**************************************************************
    Problem: 1088
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:20 ms
    Memory:1396 kb
****************************************************************/
 
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
 
int main() {
    int N, arr[10005];
    int dp[10005][2][2];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", arr + i);
    memset(dp, 0, sizeof(dp));
    if (arr[0] == 0) dp[0][0][0] = 1;
    else if (arr[0] == 1) dp[0][0][1] = dp[0][1][0] = 1;
    else if (arr[0] == 2) dp[0][1][1] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                int prev = arr[i] - j - k;
                if (prev < 0 || prev > 2) continue;
                dp[i][j][k] += dp[i - 1][prev][j];
            }
        }
    }
    int res = dp[N - 1][0][0] + dp[N - 1][1][0];
    printf("%d\n", res);
    return 0;
}
