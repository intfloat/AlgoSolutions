#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int win[20][20], N;
bool dp[16][1 << 16];
vector<int> arr[16];
vector<int> split[1 << 16];
void preprocess() {
    FOR(i, 1 << 16) {
        arr[__builtin_popcount(i)].push_back(i);
    }
    for (int j = 2; j <= 16; j *= 2) {
        int idx = j / 2;
        FOR(k, arr[j].size()) {
            int n1 = arr[j][k];
            FOR(p, arr[idx].size()) {
                int cur = arr[idx][p];
                if ((cur & n1) == cur && cur < n1 - cur) {
                    split[n1].push_back(cur);
                }
            }
        }
    }
}
inline void solve() {
    scanf("%d", &N);
    FOR(i, N) FOR(j, N) {
        scanf("%d", &win[i][j]);
    }
    memset(dp, false, sizeof dp);
    FOR(i, N) dp[i][1 << i] = true;
    vector<int> best(N, N / 2 + 1);
    for (int q = 2; q <= N; q *= 2) {
        for (auto j : arr[q]) {
            if (j >= (1 << N)) continue;
            FOR(i, N) {
                if ((j & (1 << i)) == 0) continue;
                FOR(k, split[j].size()) {
                    int a = split[j][k], b = j - split[j][k];
                    if ((a & (1 << i)) == 0) {
                        swap(a, b);
                    }
                    if (!dp[i][a]) continue;
                    FOR(p, N) {
                        if (win[i][p] && dp[p][b]) {
                            dp[i][j] = true;
                            break;
                        }
                    }
                    if (dp[i][j]) break;
                }
                if (dp[i][j]) {
                    best[i] = min(best[i], N / (q * 2) + 1);
                }
            }
        }
    }
    vector<int> worst(N);
    FOR(i, N) {
        if (accumulate(win[i], win[i] + N, 0) == N - 1) worst[i] = 1;
        else worst[i] = N / 2 + 1;
    }
    FOR(i, N) {
        printf("%d %d\n", best[i], worst[i]);
    }
}
int main() {
    preprocess();
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        printf("Case #%d:\n", i + 1);
        solve();
    }
    return 0;
}
