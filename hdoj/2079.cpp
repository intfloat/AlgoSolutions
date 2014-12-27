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
    int T, n, k, a, b;
    int cnt[10], dp[10][45];
    cin >> T;
    while (T--) {
        memset(cnt, 0, sizeof(cnt));
        memset(dp, 0, sizeof(dp));
        cin >> n >> k;
        FOR(i, k) { cin >> a >> b; cnt[a] += b; }
        FOR(i, cnt[1] + 1) dp[1][i] = 1;
        for (int i = 2; i <= 8; ++i) {
            for (int j = 0; j <= n; ++j) {
                int cur = 0;
                while (i * cur <= j && cur <= cnt[i]) {
                    dp[i][j] += dp[i - 1][j - i * cur];
                    ++cur;
                }
            }
        }
        cout << dp[8][n] << endl;
    }
    return 0;
}
