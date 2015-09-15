#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int MAX_N = 31;
const int n = MAX_N;
struct MATRIX {
    int matrix[MAX_N][MAX_N];
    MATRIX() {
        memset(this->matrix, 0, sizeof this->matrix);
    }
};
MATRIX matrix_add(const MATRIX& a, const MATRIX& b){
    MATRIX res;
    FOR(i, n) FOR(j, n)
        res.matrix[i][j] = (a.matrix[i][j] + b.matrix[i][j]) % MOD;
    return res;
}
MATRIX matrix_mul(const MATRIX& a, const MATRIX& b) {
    MATRIX res;
    FOR(i, n) FOR(j, n) FOR(k, n) {
        res.matrix[i][j] += ((ll)a.matrix[i][k] * (ll)b.matrix[k][j]) % MOD;
        res.matrix[i][j] %= MOD;
    }
    return res;
}
// p > 0
MATRIX matrix_power(MATRIX ma, int p) {
    MATRIX res;
    if (p == 1) return ma;
    res = matrix_power(ma, p / 2);
    res = matrix_mul(res, res);
    if (p & 1) res = matrix_mul(res, ma);
    return res;
}
int main() {
    return 0;
}
