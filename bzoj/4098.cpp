#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const ll MOD = static_cast<ll>(1e9 + 7);
int main() {
    int N;
    scanf("%d", &N);
    vector<string> g(N);
    char s[505];
    FOR(i, N) {
        scanf("%s", s);
        g[i] = s;
    }
    vector<vector<ll> > dp[2];
    FOR(i, 2) dp[i] = vector<vector<ll> >(N, vector<ll>(N, 0));
    FOR(i, N) dp[0][i][i] = 1;
    for (int i = 1; i < N; ++i) {
        int idx = (i - 1) % 2;
        FOR(j, N) fill(dp[i % 2][j].begin(), dp[i % 2][j].end(), 0);
        for (int r1 = 0; r1 < N - i; ++r1) {
            for (int r2 = i; r2 < N; ++r2) {
                if (g[r1][N - 1 - r1 - i] != g[r2][i + N - 1 - r2]) continue;
                dp[i % 2][r1][r2] = (dp[idx][r1][r2] + dp[idx][r1 + 1][r2] + dp[idx][r1 + 1][r2 - 1] + dp[idx][r1][r2 - 1]) % MOD;
            }
        }
    }
    cout << dp[(N - 1) % 2][0][N - 1] % MOD << endl;
    return 0;
}
