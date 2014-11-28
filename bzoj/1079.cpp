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
#define IFOR(i, n) for (int i = n; i >= 0; --i)
using namespace std;

const long long MOD = 1000000007;
int main() {
    int K, cnt[6], c, total = 0;
    cin >> K;
    memset(cnt, 0, sizeof(cnt));
    FOR(i, K) { cin >> c; ++cnt[c]; total += c; }
    // cout << "total: " << total << endl;
    long long dp[16][16][16][16][16][5];
    memset(dp, 0, sizeof(dp));
    if (cnt[5] > 0) dp[cnt[5] - 1][cnt[4] + 1][cnt[3]][cnt[2]][cnt[1]][4] = cnt[5];
    if (cnt[4] > 0) dp[cnt[5]][cnt[4] - 1][cnt[3] + 1][cnt[2]][cnt[1]][3] = cnt[4];
    if (cnt[3] > 0) dp[cnt[5]][cnt[4]][cnt[3] - 1][cnt[2] + 1][cnt[1]][2] = cnt[3];
    if (cnt[2] > 0) dp[cnt[5]][cnt[4]][cnt[3]][cnt[2] - 1][cnt[1] + 1][1] = cnt[2];
    if (cnt[1] > 0) dp[cnt[5]][cnt[4]][cnt[3]][cnt[2]][cnt[1] - 1][0] = cnt[1];

    int sm[6];
    sm[5] = cnt[5];
    for (int i = 4; i >= 1; --i) sm[i] = sm[i + 1] + cnt[i];
    IFOR(m5, sm[5]) IFOR(m4, sm[4]) IFOR(m3, sm[3]) IFOR(m2, sm[2]) IFOR(m1, sm[1]) {
        FOR(color, 5) FOR(nc, 5) {
            int next = nc + 1;
            long long cur = dp[m5][m4][m3][m2][m1][color];
            // cout << m3 << " " << m2 << " " << m1 << " " << t << " " << color << " " << nc << " " << cur << endl;
            if (color != next) {
                if (next == 1 && m1 > 0) dp[m5][m4][m3][m2][m1 - 1][0] = (dp[m5][m4][m3][m2][m1 - 1][0] + cur * m1) % MOD;
                if (next == 2 && m2 > 0) dp[m5][m4][m3][m2 - 1][m1 + 1][1] = (dp[m5][m4][m3][m2 - 1][m1 + 1][1] + cur * m2) % MOD;
                if (next == 3 && m3 > 0) dp[m5][m4][m3 - 1][m2 + 1][m1][2] = (dp[m5][m4][m3 - 1][m2 + 1][m1][2] + cur * m3) % MOD;
                if (next == 4 && m4 > 0) dp[m5][m4 - 1][m3 + 1][m2][m1][3] = (dp[m5][m4 - 1][m3 + 1][m2][m1][3] + cur * m4) % MOD;
                if (next == 5 && m5 > 0) dp[m5 - 1][m4 + 1][m3][m2][m1][4] = (dp[m5 - 1][m4 + 1][m3][m2][m1][4] + cur * m5) % MOD;
            }
            else {
                if (next == 1 && m1 > 0) dp[m5][m4][m3][m2][m1 - 1][0] = (dp[m5][m4][m3][m2][m1 - 1][0] + cur * m1 - cur) % MOD;
                if (next == 2 && m2 > 0) dp[m5][m4][m3][m2 - 1][m1 + 1][1] = (dp[m5][m4][m3][m2 - 1][m1 + 1][1] + cur * m2 - cur) % MOD;
                if (next == 3 && m3 > 0) dp[m5][m4][m3 - 1][m2 + 1][m1][2] = (dp[m5][m4][m3 - 1][m2 + 1][m1][2] + cur * m3 - cur) % MOD;
                if (next == 4 && m4 > 0) dp[m5][m4 - 1][m3 + 1][m2][m1][3] = (dp[m5][m4 - 1][m3 + 1][m2][m1][3] + cur * m4 - cur) % MOD;
                if (next == 5 && m5 > 0) dp[m5 - 1][m4 + 1][m3][m2][m1][4] = (dp[m5 - 1][m4 + 1][m3][m2][m1][4] + cur * m5 - cur) % MOD;
            }
        }
    }
    // cout << dp[0][0][0][2][1][0][2] << endl;
    // cout << dp[0][0][1][0][2][0][1] << endl;
    // cout << dp[0][0][1][1][0][0][0] << endl;
    // cout << dp[0][0][1][0][1][0][1] << endl;
    // cout << dp[0][0][0][1][1][0][2] << endl;
    long long res = *max_element(dp[0][0][0][0][0], dp[0][0][0][0][0] + 5);
    cout << res % MOD << endl;
    return 0;
}
