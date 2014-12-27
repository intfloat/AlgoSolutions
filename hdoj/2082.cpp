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
    vector<int> val;
    for (int i = 1; i <= 26; ++i) val.push_back(i);
    int T, dp[26][55];
    cin >> T;
    while (T--) {
        vector<int> cnt;
        FOR(i, 26) {
            int tmp;
            cin >> tmp;
            if (tmp * val[i] > 50) tmp = 50 / val[i];
            cnt.push_back(tmp);
        }
        memset(dp, 0, sizeof(dp));
        FOR(i, cnt[0] + 1) dp[0][i] = 1;
        for (int i = 1; i < val.size(); ++i) {
            for (int j = 0; j <= 50; ++j) {
                int cur = 0;
                while (val[i] * cur <= j && cur <= cnt[i]) {
                    dp[i][j] += dp[i - 1][j - val[i] * cur];
                    ++cur;
                }
            }
        }
        int res = 0;
        FOR(i, 51) res += dp[25][i];
        // empty word should be deleted
        cout << res - 1 << endl;
    }
    return 0;
}
