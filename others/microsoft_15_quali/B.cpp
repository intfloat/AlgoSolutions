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

const int MOD = 100007;
int main() {
    int T, len;
    string s;
    cin >> T;
    FOR(tt, T) {
        cin >> s;
        len = s.size();
        vector<vector<int> > dp(len, vector<int>(len + 1, 0));
        for (int i = 0; i < len; ++i) {
            for (int j = len - 1; j > i; --j) {
                if (i == 0) {
                    dp[i][j] = dp[i][j + 1];
                    if (s[i] == s[j]) dp[i][j] = (dp[i][j] + 1) % MOD;
                    continue;
                }
                dp[i][j] = (dp[i - 1][j] + dp[i][j + 1] - dp[i - 1][j + 1] + MOD) % MOD;
                if (s[i] == s[j]) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1] + 1) % MOD;                
            }
        }
        int res = 0;
        FOR(i, len) {
            if (i == 0 || i == len - 1) res = (res + 1) % MOD;
            else res = (res + 1 + dp[i - 1][i + 1]) % MOD;
        }
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (s[i] != s[j]) continue;
                if (i == 0 || j == len - 1) res = (res + 1) % MOD;
                else res = (res + dp[i - 1][j + 1] + 1) % MOD;
            }
        }
        cout << "Case #" << tt + 1 << ": " << res % MOD << endl;
    }
    return 0;
}
