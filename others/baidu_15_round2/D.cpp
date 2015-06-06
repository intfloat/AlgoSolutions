#include <stdio.h>
#include <algorithm>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAXN = 150005;
ll val[MAXN], dp[MAXN][19], cur;
int N, R, to, M;
void rmq_init() {
    for (int i = 0; i < M; ++i)
        dp[i][0] = val[i];
    for (int i = 1; (1 << i) <= M; ++i) {
        for (int j = 0; (j + (1 << i) - 1) < M; ++j) {
            dp[j][i] = max(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
        }
    }
    return;
}
inline ll query(int left, int right) {
    int k = 0;
    int length = right - left + 1;
    while ((1 << (k + 1)) < length) ++k;
    ll mx = max(dp[left][k], dp[right - (1 << k) + 1][k]);
    return mx;
}
void solve() {
    int idx;
    scanf("%d %d", &N, &R);
    M = N + N / 2;
    vector<ll> H(N);
    FOR(i, N) scanf("%lld", &H[i]);
    for (int i = 0; i < N; ++i) {
        to = (i + 1) % N;
        val[i] = R + (H[to] - H[i]);
    }
    for (int i = N; i < M; ++i) val[i] = val[i - N];
    for (int i = 1; i < M; ++i) val[i] += val[i - 1];
    rmq_init();
    ll res = -1;
    FOR(i, N) {
        to = (i + N / 2 - 1);
        cur = H[i] + query(i, to) + H[i];
        if (i > 0) cur = cur - val[i - 1];
        if (cur > res) {
            res = cur;
            idx = i;
        }
    }
    for (int j = idx + 1; j % N != idx; ++j) {
        if (H[idx] + H[j % N] + (ll)R * (j - idx) == res) {
            int r1 = idx + 1, r2 = j % N + 1;
            if (r1 > r2) swap(r1, r2);
            printf("%d %d\n", r1, r2);
            return;
        }
    }
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
