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

typedef long long ll;

int M, N, K, L;
vector<ll> sum[5];
deque<pair<ll, int> > q[5][5];
int main() {
    vector<ll> dp[5];
    scanf("%d %d %d %d", &M, &N, &K, &L);
    FOR(i, N) { sum[i].resize(M + 1); sum[i][0] = 0; dp[i].resize(M + 1); }
    FOR(i, N) FOR(j, M) {
        int t;
        scanf("%d", &t);
        sum[i][j + 1] = sum[i][j] + t;
    }
    FOR(i, N) dp[i][0] = 0;
    FOR(i, N) FOR(j, N) { q[i][j].push_back(make_pair(0, 0)); }

    // still need to check if this is correct, but i am starving....
    for (int i = 1; i <= M; ++i) {
        FOR(j, N) {
            dp[j][i] = 1e14;
            if (i <= L) {
                dp[j][i] = sum[j][i];
            }
            FOR(k, N) {
                if (j == k) continue;
                while (!q[k][j].empty() && q[k][j].front().second < i - L) q[k][j].pop_front();
                assert(q[k][j].front().second < i);
                dp[j][i] = min(dp[j][i], q[k][j].front().first + sum[j][i] + K);
            }
        }
        FOR(j, N) FOR(k, N) {
            if (k == j) continue;
            ll tmp = dp[j][i] - sum[k][i];
            while (!q[j][k].empty() && tmp <= q[j][k].back().first) q[j][k].pop_back();
            q[j][k].push_back(make_pair(tmp, i));
        }
    }

    ll res = dp[0][M];
    FOR(i, N) res = min(res, dp[i][M]);
    cout << res << endl;
    return 0;
}
