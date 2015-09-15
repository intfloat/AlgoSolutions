#include <string.h>
#include <stdio.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int MAX_N = 128;
int n = MAX_N;
struct MATRIX {
    int matrix[MAX_N][MAX_N];
};
MATRIX matrix_mul(const MATRIX& a, const MATRIX& b) {
    MATRIX res;
    memset(res.matrix, 0, sizeof res.matrix);
    FOR(i, n) FOR(j, n) FOR(k, n) {
        res.matrix[i][j] += ((ll)a.matrix[i][k] * (ll)b.matrix[k][j]) % MOD;
        res.matrix[i][j] %= MOD;
    }
    return res;
}
MATRIX matrix_power(MATRIX ma, int p) {
    MATRIX res;
    if (p == 1) return ma;
    res = matrix_power(ma, p / 2);
    res = matrix_mul(res, res);
    if (p & 1) res = matrix_mul(res, ma);
    return res;
}
MATRIX base;
inline bool check(int i, int j) {
    FOR(k, 7) {
        if (!(j & (1 << k))) continue;
        if (i & (1 << k)) continue;
        if (k && !(j & (1 << (k - 1))) && (i & (1 << (k - 1)))) return false;
        if (!(j & (1 << (k + 1))) && (i & (1 << (k + 1)))) return false;
    }

    return true;
}
inline void preprocess() {
    FOR(i, 1 << 7) FOR(j, 1 << 7) {
        bool ok = check(i, j) && check(j, i);
        base.matrix[i][j] = ok;
    }
}
int main() {
    int row, col;
    preprocess();
    while (scanf("%d %d", &row, &col) != EOF) {
        n = (1 << col);
        if (row == 1) {
            printf("%d\n", 1 << col);
            continue;
        }
        MATRIX res = matrix_power(base, row - 1);
        ll cnt = 0ll;
        FOR(i, n) FOR(j, n) {
            cnt = (cnt + res.matrix[i][j]) % MOD;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
