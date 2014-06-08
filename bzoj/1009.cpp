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
using namespace std;


// all operations are in MOD sense
int MOD;
const int MAXN = 21;
struct MATRIX{  
    int matrix[MAXN][MAXN];  
}; 

int n;  

// adding operation for matrix
MATRIX matrix_add(MATRIX a,MATRIX b){  
    MATRIX tmp;  
    for(int i=0;i<n;i++)  
    for(int j=0;j<n;j++)  
        tmp.matrix[i][j]=(a.matrix[i][j]+b.matrix[i][j])%MOD;  
    return tmp;  
}  

// multiplication for matrix
MATRIX matrix_mul(MATRIX a,MATRIX b){  
    MATRIX tmp;  
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
MATRIX matrix_mi(MATRIX ma,int p){  
    MATRIX tmp;  
    if(p==1)  
        return ma;  
    tmp=matrix_mi(ma,p/2);  
    tmp=matrix_mul(tmp,tmp);  
    if(p%2==1)  
        tmp=matrix_mul(tmp,ma);  
    return tmp;  
}  

MATRIX mat;
string s;
MATRIX calc() {
	MATRIX r;
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			r.matrix[i][j] = 0;

	for(int i=0; i<=n; i++) {
		string cur = s.substr(0, i);
		for(char c='0'; c<='9'; c++) {
			string t1 = cur + c;
			bool check = false;
			for(int j=t1.size(); j>0; j--) {
				if(s.substr(0, j)==t1.substr(t1.size()-j, j)) {
					r.matrix[j][i]++;
					check = true;
					break;
				}
			}
			if(!check) r.matrix[0][i]++;
		}
	}
	return r;
}

int main(){
	int total;
	cin>>total>>n>>MOD;	
	cin>>s;
	assert(s.size() == n);
	mat = calc();
	mat = matrix_mi(mat, total);
	long long res = 0;
	// the sum of first column is final result
	for(int i=0; i<=n; i++) {
		res = (res + mat.matrix[i][0]) % MOD;
	}
	cout<<res<<endl;
	return 0;
}
