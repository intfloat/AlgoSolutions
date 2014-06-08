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
using namespace std;

const long long MOD = 100003;
long long fast_pow(long long a, long long b) {
	if (b == 0) return 1ll;
	if (b == 1) return a%MOD;
	long long t = fast_pow(a, b/2);
	t = (t*t)%MOD;
	if(b%2 == 1) t = (t*(a%MOD))%MOD;
	return t%MOD;
}
// res = M^N - M*(M - 1)^(N-1)
int main() {
	long long M, N;
	cin>>M>>N;
	long long a = fast_pow(M, N);
	long long b = fast_pow(M-1, N-1);
	b = ((M%MOD) * b)%MOD;
	long long res = (a - b + 2*MOD)%MOD;
	cout<<res<<endl;
	return 0;
}
