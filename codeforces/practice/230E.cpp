#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <string.h>
#include <ctime>

using namespace std;

// all operations are in MOD sense
long long MOD = 1000000007ll;
const int MAXN = 83;
struct MATRIX{  
    long long matrix[MAXN][MAXN];  
}; 

MATRIX eye(){
    MATRIX tmp;
    memset(tmp.matrix, 0, sizeof(tmp.matrix));
    for(int i=0; i<MAXN; i++)
        tmp.matrix[i][i] = 1;
    return tmp;
}

// multiplication for matrix
MATRIX matrix_mul(MATRIX a,MATRIX b){  
    MATRIX tmp;  
    int n = MAXN;
    for(int i=0;i<n;i++)  
    for(int j=0;j<n;j++)  
        tmp.matrix[i][j]=0;  
    for(int i=0;i<n;i++)  
    for(int j=0;j<n;j++)  
    for(int k=0;k<n;k++){  
        tmp.matrix[i][j]+=(a.matrix[i][k]*b.matrix[k][j])%MOD;  
        tmp.matrix[i][j]%=MOD;  
    }  
    return tmp;  
}  

// fast power operation for matrix
// use divide and conquer strategy
MATRIX matrix_mi(MATRIX ma,long long p){  
    MATRIX tmp;  
    if(p == 0) return eye();
    if(p==1)  
        return ma;  
    tmp=matrix_mi(ma,p/2);  
    tmp=matrix_mul(tmp,tmp);  
    if(p%2==1)  
        tmp=matrix_mul(tmp,ma);  
    return tmp;  
}  

int main(){
	long long nn;
	int k;
	cin>>nn>>k;
	long long c[45][45];
	memset(c, 0, sizeof(c));
	c[0][0] = 1;
	for(int i=1; i<45; i++){
		c[i][0] = 1;
		for(int j=1; j<=i; j++){
			c[i][j] = (c[i-1][j-1]+c[i-1][j])%MOD;
		}
	}
	long long two[45];
	memset(two, 0, sizeof(two));
	two[0] = 1;
	for(int i=1; i<45; i++) two[i] = (two[i-1]*2)%MOD;
	MATRIX mat;
	memset(mat.matrix, 0, sizeof(mat.matrix));
	for(int i=0; i<=40; i++){
		mat.matrix[i+41][i] = 1;
		for(int j=0; j<=40; j++){
			if(i>=j){
				mat.matrix[i][j] = c[i][j]%MOD;
				mat.matrix[i][j+41] = (c[i][j]*two[i-j])%MOD;
			}
		}
	}
	mat.matrix[82][82] = 1;
	mat.matrix[82][k] = 1;
	MATRIX A = matrix_mi(mat, nn-1);
	long long cur[83];
	memset(cur, 0, sizeof(cur));
	for(int i=0; i<=40; i++){
		cur[i] = two[i+1];
		cur[i+41] = 1;
	}
	cur[82] = 1;
	long long res = 0;
	for(int i=0; i<83; i++)
		res = (res+(A.matrix[82][i]*cur[i])%MOD)%MOD;
	cout<<res<<endl;
}
