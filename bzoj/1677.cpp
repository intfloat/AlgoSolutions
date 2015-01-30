/**************************************************************
    Problem: 1677
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:56 ms
    Memory:9012 kb
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
using namespace std;

const long long MOD = (long long)1e9;
int main() {
    int n;
    long long dp[1000005];
    cin >> n;
    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        if (i % 2) dp[i] = dp[i - 1];
        else dp[i] = (dp[i>>1] + dp[i - 2]) % MOD;
    }
    cout << dp[n] % MOD << endl;
    return 0;
}
