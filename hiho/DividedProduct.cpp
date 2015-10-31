#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9 + 7);
ll dp[101][101][51];
int main() {
    int N, M;
    cin >> N >> M;
    memset(dp, 0, sizeof dp);
    dp[0][0][M] = 1;
    for (int i = 0; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            for (int k = 1; k <= M; ++k) {
                if (dp[i][j][k] == 0) continue;
                for (int p = i + 1; p + j <= N; ++p) {
                    int rem = k / __gcd(k, p);
                    dp[p][p + j][rem] = (dp[p][p + j][rem] + dp[i][j][k]) % MOD;
                }
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= N; ++i) {
        res = (res + dp[i][N][1]) % MOD;
    }
    cout << res << endl;
    return 0;
}
