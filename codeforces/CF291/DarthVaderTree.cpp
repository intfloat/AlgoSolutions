#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const int MOD = static_cast<int>(1e9 + 7);
struct Matrix {
    ll arr[101][101];
};

Matrix multiply(Matrix& a, Matrix& b) {
    Matrix c;
    memset(c.arr, 0, sizeof(c.arr));
    FOR(i, 101) FOR(j, 101) FOR(k, 101)
        c.arr[i][j] = (c.arr[i][j] + a.arr[i][k] * b.arr[k][j]) % MOD;
    return c;
}

Matrix fast_power(Matrix& a, int p) {
    if (p == 1) return a;
    Matrix c = fast_power(a, p / 2);
    c = multiply(c, c);
    if (p % 2) c = multiply(a, c);
    return c;
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    vector<int> d(n);
    FOR(i, n) scanf("%d", &d[i]);
    vector<ll> res(100, 0);
    res[0] = 1;
    for (int i = 1; i < res.size(); ++i) {
        FOR(j, d.size()) {
            if (i >= d[j]) res[i] = (res[i] + res[i - d[j]]) % MOD;
        }
        res[i] = (res[i] + 1) % MOD;
    }
    if (x <= 99) {
        printf("%d\n", res[x]);
        return 0;
    }
    
    // construct a transition matrix
    Matrix val;
    memset(val.arr, 0, sizeof(val.arr));
    FOR(i, d.size()) ++val.arr[0][d[i] - 1];
    val.arr[0][100] = 1;
    for (int i = 1; i < 100; ++i) val.arr[i][i - 1] = 1;
    val.arr[100][100] = 1;

    Matrix pr = fast_power(val, x - 99);
    ll t = 0;
    reverse(res.begin(), res.end());
    FOR (i, 100) t = (t + pr.arr[0][i] * res[i]) % MOD;
    t = (t + pr.arr[0][100]) % MOD;
    printf("%d\n", t);
    return 0;
}
