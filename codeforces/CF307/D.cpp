#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
// all operations are in MOD space
ll N, k, len, MOD;
const int MAXN = 2;
const int n = MAXN;
struct MATRIX {
    ll matrix[MAXN][MAXN];
};
MATRIX matrix_add(MATRIX a, MATRIX b){
    MATRIX tmp;
    FOR(i, n) FOR(j, n)
        tmp.matrix[i][j] = (a.matrix[i][j] + b.matrix[i][j])%MOD;
    return tmp;
}
MATRIX matrix_mul(MATRIX a, MATRIX b){
    MATRIX res;
    FOR(i, n) FOR(j, n)
        res.matrix[i][j] = 0;
    FOR(i, n) FOR(j, n) FOR(k, n) {
        res.matrix[i][j] += (a.matrix[i][k] * b.matrix[k][j])%MOD;
        res.matrix[i][j] %= MOD;
    }
    return res;
}
MATRIX matrix_mi(MATRIX ma, ll p){
    MATRIX tmp;
    if(p == 1)  return ma;
    tmp = matrix_mi(ma, p / 2);
    tmp = matrix_mul(tmp, tmp);
    if(p % 2) tmp = matrix_mul(tmp, ma);
    return tmp;
}
ll pw(ll number, ll p) {
    if (p == 0) return 1;
    if (p == 1) return number % MOD;
    ll t = pw(number, p / 2);
    t = (t * t) % MOD;
    if (p % 2) t = (t * number) % MOD;
    return t;
}
int main() {
    cin >> N >> k >> len >> MOD;
    if (MOD == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (len == 0) {
        if (k == 0) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    ll total = pw(2ll, N);
    ll tmp = k;
    FOR(i, len) {
        tmp = tmp & (~(1ll << i));
    }
    if (tmp != 0) {
        cout << 0 << endl;
        return 0;
    }
    MATRIX mt;
    mt.matrix[0][0] = mt.matrix[0][1] = mt.matrix[1][0] = 1;
    mt.matrix[1][1] = 0;
    MATRIX pmt = matrix_mi(mt, N - 1);
    ll cnt = (pmt.matrix[0][0] + pmt.matrix[0][1]) % MOD;
    cnt = (cnt + pmt.matrix[1][0] + pmt.matrix[1][1]) % MOD;
    ll res = 1ll;
    // cout << "DEBUG: " << total << " " << cnt << endl;
    FOR(i, len) {
        if (k & (1ll << i)) {
            res = (res * ((total - cnt + MOD) % MOD)) % MOD;
        }
        else {
            res = (res * cnt) % MOD;
        }
    }
    cout << res << endl;
    return 0;
}
