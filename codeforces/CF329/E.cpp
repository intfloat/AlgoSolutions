#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int MAX_N = 20;
int n, row, col;
int init[MAX_N][MAX_N];
const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};
struct MATRIX {
    int matrix[MAX_N][MAX_N];
    MATRIX() {
        memset(this->matrix, 0, sizeof this->matrix);
    }
};
MATRIX eye;
void preprocess() {
    memset(init, 0, sizeof init);
    FOR(i, n) {
        init[i][i] = 1;
        int r = i / col, c = i % col;
        FOR(j, 4) {
            int nr = r + dir_x[j], nc = c + dir_y[j];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
            init[i][nr * col + nc] = 1;
        }
    }
    FOR(i, n) eye.matrix[i][i] = 1;
}
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
MATRIX matrix_power(MATRIX ma, int p) {
    if (p == 0) return eye;
    if (p == 1) return ma;
    MATRIX res = matrix_power(ma, p / 2);
    res = matrix_mul(res, res);
    if (p & 1) res = matrix_mul(res, ma);
    return res;
}
vector<int> res;
inline void multiply(MATRIX m, vector<int>& val) {
    fill(res.begin(), res.end(), 0);
    FOR(i, res.size()) {
        FOR(j, val.size()) {
            res[i] = ((ll)res[i] + (ll)(m.matrix[i][j]) * val[j]) % MOD;
        }
    }
}
int main() {
    int q, type, x, y, t;
    scanf("%d %d %d", &row, &col, &q);
    n = row * col;
    preprocess();
    MATRIX st;
    memcpy(st.matrix, init, sizeof init);
    int cur = 1;
    vector<int> val(n, 0);
    res.resize(n);
    val[0] = 1;
    FOR(i, q) {
        scanf("%d %d %d %d", &type, &x, &y, &t);
        --x; --y;
        if (type == 1) {
            multiply(matrix_power(st, t - cur), val);
            val = res; cur = t;
            printf("%d\n", res[x * col + y]);
        }
        else if (type == 2) {
            multiply(matrix_power(st, t - 1 - cur), val);
            val = res; cur = t - 1;
            int num = x * col + y;
            FOR(j, n) st.matrix[num][j] = 0;
        }
        else if (type == 3) {
            multiply(matrix_power(st, t - cur), val);
            val = res; cur = t;
            int num = x * col + y;
            FOR(j, n) st.matrix[num][j] = init[num][j];
        }
    }
    return 0;
}
