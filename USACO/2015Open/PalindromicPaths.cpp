#include <iostream>
#include <string>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const ll MOD = static_cast<ll>(1e9 + 7);
int main() {
    freopen("palpath.in", "r", stdin);
    freopen("palpath.out", "w", stdout);
    int N;
    cin >> N;
    vector<string> g(N);
    FOR(i, N) cin >> g[i];
    vector<vector<ll> > prev(N, vector<ll>(N, 0)), cur(N, vector<ll>(N, 0));
    FOR(i, N) prev[i][i] = 1;
    for (int i = 1; i < N; ++i) {
        FOR(j, cur.size()) fill(cur[j].begin(), cur[j].end(), 0);
        for (int r1 = 0; r1 < N - i; ++r1) {
            for (int r2 = i; r2 < N; ++r2) {
                if (g[r1][N - 1 - r1 - i] != g[r2][i + N - 1 - r2]) continue;
                cur[r1][r2] = (prev[r1][r2] + prev[r1 + 1][r2] + prev[r1 + 1][r2 - 1] + prev[r1][r2 - 1]) % MOD;
            }
        }
        prev = cur;
    }
    cout << cur[0][N - 1] % MOD << endl;
    return 0;
}
