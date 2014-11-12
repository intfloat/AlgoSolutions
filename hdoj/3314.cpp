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
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MAX_N = 100005;
int p[MAX_N], rank[MAX_N], ok[MAX_N];

int _find(int u) {
	if (u == p[u]) return u;
	p[u] = _find(p[u]);
	return p[u];
}

void _union(int from, int to) {
	ok[from] = false;
	int pu = _find(from), pv = _find(to);	
	if (from != to) {
		p[pu] = pv;
		rank[pv] += rank[pu];
	}
	return;
}

int main() {
	int N;
	while (cin >> N && N) {
		FOR(i, N) { p[i] = i; rank[i] = 1; ok[i] = true; }		
		FOR(i, N) {
			int t;
			scanf("%d", &t);
			if (i != t) _union(i, t);
		}
		int pos, mx = -1, cnt = 0;
		FOR(i, N) {
			if (!ok[i]) continue;
			if (rank[i] > mx) { cnt = 1; mx = rank[i]; pos = i; }
			else if (rank[i] == mx) ++cnt;
		}
		if (cnt > 1 || mx < 0) cout << "Trouble" << endl;
		else cout << pos << endl;
	}
	return 0;
}
