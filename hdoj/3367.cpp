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

const int MAX_N = 10005;
struct Edge {
	int u, v, w;
	Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};

bool cmp(const Edge& e1, const Edge& e2) {
	return e1.w > e2.w;
}

vector<Edge> v;
int p[MAX_N];
bool has_circle[MAX_N];

int _find(int u) {
	if (p[u] == u) return u;
	p[u] = _find(p[u]);
	return p[u];
}

bool _union(int u, int v) {
	int pu = _find(u), pv = _find(v);
	if (pu == pv) {
		if (!has_circle[pu]) { has_circle[pu] = true; return true; }
		else return false;
	}
	// pu != pv
	if (has_circle[pu] && has_circle[pv]) return false;
	if (has_circle[pu] && !has_circle[pv]) { p[pv] = pu; return true; }
	if (!has_circle[pu] && has_circle[pv]) { p[pu] = pv; return true; }
	else { p[pu] = pv; return true; }
}

int main() {
	int N, M;
	while (cin >> N >> M && N) {
		v.clear();
		FOR(i, M) {
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			v.push_back(Edge(x, y, w));
		}
		sort(v.begin(), v.end(), cmp);
		FOR(i, N + 1) p[i] = i;
		memset(has_circle, false, sizeof(has_circle));
		int res = 0;
		FOR(i, v.size()) {
			if (_union(v[i].u, v[i].v)) res += v[i].w;
		}
		cout << res << endl;
	}
	return 0;
}
