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
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MAX_N = 125;
int main() {
    int N, dp[MAX_N][MAX_N];
    while (cin >> N) {
        memset(dp, 0, sizeof(dp));
        FOR(i, N + 1) dp[1][i] = 1;
        for (int i = 2; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                int cur = 0;
                while (i * cur <= j) {
                    dp[i][j] += dp[i - 1][j - i * cur];
                    ++cur;
                }
            }
        }
        cout << dp[N][N] << endl;
    }
    return 0;
}
