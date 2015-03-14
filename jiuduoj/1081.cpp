#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MOD = 10000;
const int MAXN = 2;
const int n = MAXN;
struct MATRIX {
    int matrix[MAXN][MAXN];
};

// multiplication for matrix
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

// fast power operation for matrix
// use divide and conquer strategy
MATRIX matrix_mi(MATRIX ma, int p){  
    MATRIX tmp;  
    if(p == 1)  return ma;  
    tmp = matrix_mi(ma, p / 2);
    tmp = matrix_mul(tmp, tmp);
    if(p & 1) tmp = matrix_mul(tmp, ma);
    return tmp;
}

int main() {
    int a0, a1, p, q, k;
    while (cin >> a0 >> a1 >> p >> q >> k) {
        a0 %= MOD; a1 %= MOD; p %= MOD; q %= MOD;
        if (k == 0) cout << a0 << endl;
        else if (k == 1) cout << a1 << endl;
        else {            
            MATRIX base;
            base.matrix[0][0] = p; base.matrix[0][1] = q;
            base.matrix[1][0] = 1; base.matrix[1][1] = 0;
            MATRIX res = matrix_mi(base, k - 1);
            cout << (res.matrix[0][0] * a1 + res.matrix[0][1] * a0) % MOD << endl;
        }
    }
    return 0;
}
