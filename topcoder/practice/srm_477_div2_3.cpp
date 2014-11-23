// wrong answer ×´Ì¬¡£¡£¡£ 

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
#include <ctime>
#define MOD 1000000007

using namespace std;


class CarelessSecretary {
public:
	long long arr[15][1005];
	int howMany(int, int);
	long long f(long long k, long long n){
		if(arr[k][n] != 0)
			return arr[k][n];
		if(k == 0){
			arr[k][n] = n;
		}
		else if(k == 1)
			arr[k][n] = n-1;
		else{
			arr[k][n] = ((n-k)*f(k-1, n-1))%MOD+((k-1)*f(k-2, n-1))%MOD;
		}
		arr[k][n] = arr[k][n]%MOD;
		return arr[k][n];
	}
};

int CarelessSecretary::howMany(int N, int K) {
	long long res = 0;
	memset(arr, 0, sizeof(arr));
	res = f(K, N);
	for(long long i=N-K; i>=1; i--)
		res = (res*i)%MOD;
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
