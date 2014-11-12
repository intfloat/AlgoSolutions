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

const long long MOD = 1000000007;
int* p;

int _find(int u) {
	if (p[u] == u) return u;
	p[u] = _find(p[u]);
	return p[u];
}

bool _union(int u, int v) {
	int pu = _find(u), pv = _find(v);
	if (pu == pv) return false;
	p[pu] = pv;
	return true;
}

long long fast_power(int number, int pw) {
	if (pw == 0) return 1;
	if (pw == 1) return number % MOD;
	long long t = fast_power(number, pw / 2);
	if (pw % 2) return (((t * t) % MOD) * number) % MOD;
	else return (t * t) % MOD;
}

int main() {
	int N, M, cnt;
	while(cin >> N >> M) {
		cnt = 0;
		p = new int[N + 5];
		for (int i = 1; i <= N + 1; ++i) p[i] = i;
		for (int i = 0; i < M; ++i) {
			int x, y;
			cin >> x >> y;
			cnt += _union(x, y + 1);
		}
		cout << fast_power(26, N - cnt) << endl;
		delete p;
	}
	return 0;
}
