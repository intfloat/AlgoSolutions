#include <vector>
#include <list>
#include <map>
#include <set>
#include <string.h>
#include <deque>
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

using namespace std;

class ExactTree {
public:
    int getTree(int, int, int);
};

int ExactTree::getTree(int n, int m, int r) {
    bool dp[55][105];
    int val[55][105];
    memset(dp, false, sizeof dp);
    dp[1][0] = true;
    val[1][0] = 0;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i < len; ++i) {
            for (int p = 0; p < m; ++p) for (int q = 0; q < m; ++q) {
                if (dp[i][p] && dp[len - i][q]) {
                    int t = val[i][p] + val[len - i][q] + i * (n - i);
                    if (!dp[len][t % m]) {
                        dp[len][t % m] = true;
                        val[len][t % m] = t;
                    }
                    else {
                        val[len][t % m] = min(val[len][t % m], t);
                    }
                }
            }
        }
    }
    if (dp[n][r]) {
        return val[n][r];
    }
    else {
        return -1;
    }
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
// 9 23 10 expect: 102
