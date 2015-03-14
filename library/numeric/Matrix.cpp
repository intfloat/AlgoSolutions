#include <iostream>
#define FOR(i, n) for (int i = 0; i < n; ++i) 
using namespace std;  

// all operations are in MOD space
const int MOD = 100000007;
const int MAXN = 31;
const int n = MAXN;
struct MATRIX {
    int matrix[MAXN][MAXN];  
};

// adding operation for matrix
MATRIX matrix_add(MATRIX a, MATRIX b){  
    MATRIX tmp;  
    FOR(i, n) FOR(j, n)    
        tmp.matrix[i][j] = (a.matrix[i][j] + b.matrix[i][j])%MOD;  
    return tmp;
}  

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

int main(){   
    // TODO: need to add some test code
    return 0;  
}
