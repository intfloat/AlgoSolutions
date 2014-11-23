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

const int MOD = 1000000007;
int main() {
	long long a, b;
	cin >> a >> b;
	long long res = (b * (b - 1)) / 2;
	res %= MOD;
	long long t = (a * (a + 1)) / 2;
	t %= MOD;
	t = (t * b) % MOD;
	t = (t + a) % MOD;
	res = (res * t) % MOD;
	cout << res << endl;
	return 0;
}
