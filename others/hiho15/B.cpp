#include <stdio.h>
#include <vector>
#include <string.h>
#include <limits.h>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 301;
const ll MOD = (ll)(1e9 + 7);
const int R = 23;
int A[MAX_N][MAX_N], B[MAX_N][MAX_N], n, C[MAX_N][MAX_N];
ll ha[MAX_N], hb[MAX_N];
inline void calc_hash(ll T[MAX_N], int S[MAX_N][MAX_N]) {
    for (int i = 1; i <= n; ++i) {
        T[i] = 0;
        for (int j = 1; j <= n; ++j) {
            T[i] = (R * T[i] + S[i][j]) % MOD;
        }
    }
}
inline int solve(int perm[MAX_N]) {
    vector<bool> visited(n + 1, false);
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        ++ret;
        visited[i] = true;
        int ptr = perm[i];
        while (!visited[ptr]) {
            visited[ptr] = true;
            ptr = perm[ptr];
        }
    }
    return n - ret;
}
int main() {
    int res = INT_MAX;
    scanf("%d", &n);
    FOR(i, n) FOR(j, n) scanf("%d", &A[i + 1][j + 1]);
    FOR(i, n) FOR(j, n) scanf("%d", &B[i + 1][j + 1]);
    int pos[MAX_N], np[MAX_N], cp[MAX_N];
    calc_hash(hb, B);
    for (int i = 1; i <= n; ++i) pos[B[1][i]] = i;
    for (int l = 1; l <= n; ++l) {
        for (int i = 1; i <= n; ++i) {
            np[i] = pos[A[l][i]];
        }
        int cur = solve(np);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int t = np[j];
                C[i][t] = A[i][j];
            }
        }
        calc_hash(ha, C);
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            int index = find(hb + 1, hb + n + 1, ha[i]) - hb;
            if (index > n) {
                ok = false;
                break;
            }
            cp[i] = index;
        }
        if (!ok) continue;
        cur += solve(cp);
        res = min(res, cur);
    }
    if (res == INT_MAX) printf("-1\n");
    else printf("%d\n", res);
    return 0;
}
