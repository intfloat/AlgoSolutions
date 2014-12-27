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

int main() {
    int N, dp[20][305];
    vector<int> val;
    for (int i = 1; i <= 17; ++i) val.push_back(i * i);
    while (cin >> N && N > 0) {
        memset(dp, 0, sizeof(dp));
        FOR(i, N + 1) dp[0][i] = 1;
        for (int i = 1; i < val.size(); ++i) {
            for (int j = 0; j <= N; ++j) {
                int cur = 0;
                while (cur * val[i] <= j) {
                    dp[i][j] += dp[i - 1][j - cur * val[i]];
                    ++cur;
                }
            }
        }
        cout << dp[val.size() - 1][N] << endl;
    }
    return 0;
}
