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

int dp[35][35], ans[35];

void gaussian() {
    FOR(i, 30) {
        int pos = -1;
        for (pos = i; pos < 30; ++pos) if (dp[pos][i]) break;
        assert(pos >= 0);
        FOR(j, 31) swap(dp[i][j], dp[pos][j]);
        FOR(j, 30) {
            if (i == j || dp[j][i] == 0) continue;
            FOR(k, 31) dp[j][k] ^= dp[i][k];
        }
    }
    FOR(i, 30) ans[i] = dp[i][30];
    return;
}

int main() {
    int n;
    cin >> n;
    FOR(tt, n) {
        memset(dp, 0, sizeof(dp));
        memset(ans, 0, sizeof(ans));
        FOR(i, 30) cin >> dp[i][30];
        FOR(i, 30) {
            dp[i][i] = 1;
            if (i % 6 != 5) dp[i][i + 1] = 1;
            if (i % 6 != 0) dp[i][i - 1] = 1;
            if (i >= 6) dp[i][i - 6] = 1;
            if (i + 6 < 30) dp[i][i + 6] = 1;
        }
        gaussian();
        cout << "PUZZLE #" << (tt + 1) << endl;
        FOR(i, 5) {
            cout << ans[i * 6];
            for (int j = 1; j < 6; ++j) cout << " " << ans[i * 6 + j];
            cout << endl;
        }
    }
    return 0;
}
