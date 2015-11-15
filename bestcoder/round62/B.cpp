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
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1000000007;
const int MAX_N = 78;
const int n = MAX_N;
struct MATRIX {
    int matrix[MAX_N][MAX_N];
    MATRIX() {
        memset(this->matrix, 0, sizeof this->matrix);
    }
};
static MATRIX get_eye() {
    MATRIX res;
    FOR(i, MAX_N) res.matrix[i][i] = 1;
    return res;
}
const MATRIX eye = get_eye();
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
// p >= 0
MATRIX matrix_power(MATRIX ma, int p) {
    if (p == 0) return eye;
    if (p == 1) return ma;
    MATRIX res = matrix_power(ma, p / 2);
    res = matrix_mul(res, res);
    if (p & 1) res = matrix_mul(res, ma);
    return res;
}
MATRIX st;
vector<ll> init(MAX_N, 0);
ll get(ll p) {
    MATRIX ff = matrix_power(st, p - 1);
    ll ret = 0;
    for (int d = 0; d <= 10; ++d) {
        int pos = d * 7;
        FOR(col, MAX_N) {
            if (init[col]) {
                ret = (ret + ff.matrix[pos][col]) % MOD;
            }
        }
    }
    // cout << p << " " << ret << endl;
    return ret;
}
inline void solve() {
    ll l, r, k;
    cin >> l >> r >> k;
    memset(st.matrix, 0, sizeof st.matrix);
    FOR(row, 70) FOR(col, 70) {
        int x1 = row / 7, r1 = row % 7;
        int x2 = col / 7, r2 = col % 7;
        if (x1 + x2 != k && (10 * r2 + x1) % 7 == r1) {
            st.matrix[row][col] = 1;
        }
    }
    for (int r = 0; r < 7; ++r) {
        FOR(col, 70) {
            int r2 = col % 7;
            if (r2 == r) st.matrix[70 + r][col] = 1;
        }
        st.matrix[70 + r][70 + r] = 1;
    }
    ll res = get(r);
    if (l > 1) res = (res - get(l - 1) + MOD) % MOD;
    cout << res << endl;
}
int main() {
    FOR(i, 70) {
        int x = i / 7, r = i % 7;
        if (x % 7 == r) init[i] = 1;
    }
    init[0] = 0;
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
