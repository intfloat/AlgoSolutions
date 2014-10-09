/**************************************************************
    Problem: 1087
    User: BananaTree
    Language: C++
    Result: Accepted
    Time:64 ms
    Memory:4852 kb
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
    int n, k;   
    cin >> n >> k;  
    vector<int> v;
    // check if i is a feasible state
    for (int i = 0; i < (1<<n); ++i) {
        int cnt = __builtin_popcount(i);
        if (cnt > k) continue;
        if (i & (i << 1)) continue;
        v.push_back(i);
        // bool ok = true;
        // for (int j = 0; j < n; ++j) {
        //  if ( ((1<<j)&i) 
        //      && (1<<(j + 1)&i) ) {
        //      ok = false;
        //      break;
        //  }
        // }
        // if (ok) v.push_back(i);
    }
    int len = v.size();
    long long dp[10][85][550];
    memset(dp, 0, sizeof(dp));
    // first row
    for (int i = 0; i < len; ++i) {
        ++dp[0][__builtin_popcount(v[i])][v[i]];
    }
    // for the remaining rows
    for (int row = 1; row < n; ++row) {
        for (int i = 0; i < len; ++i) {
            int status = v[i];
            int cur = __builtin_popcount(status);
            for (int c = cur; c <= k; ++c) {
                int prev = c - cur;
                for (int j = 0; j < len; ++j) {
                    int ps = v[j];
                    if ((ps&status) || ((ps>>1)&status) || ((ps<<1)&status)) continue;
                    else dp[row][c][status] += dp[row - 1][prev][ps];
                }
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < len; ++i) res += dp[n - 1][k][v[i]];
    cout << res << endl;
    return 0;
}
