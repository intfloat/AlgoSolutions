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

typedef pair<int, int> ii;

const int MAX_EDGE = 200005;
const int MAXN = 2 * MAX_EDGE;
int n, m, k;
ii g[MAX_EDGE * 2], ng[MAX_EDGE * 2];
bool attacked[MAXN];
int cnt[MAXN];
int p[MAXN], conn;

int _find(int x) {
	if (p[x] == x) return x;
	p[x] = _find(p[x]);
	return p[x];
}

void _union(int x, int y) {
	int px = _find(x);
	int py = _find(y);
	if (px != py) {
		p[px] = py;
		--conn;
	}
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	memset(cnt, 0, sizeof(cnt));
	memset(attacked, false, sizeof(attacked));	
	for (int i=0; i<n; i++) p[i] = i;
	conn = 0;
	for (int i=0; i<m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		assert(x != y);
		assert(x<n && y<n);
		g[i * 2] = make_pair(x, y);
		g[i * 2 + 1] = make_pair(y, x);
		++cnt[x]; ++cnt[y];
	}
	for (int i=1; i<n; i++) cnt[i] += cnt[i-1];
	cnt[n] = cnt[n - 1];
	assert(cnt[n] == 2*m);
	// counting sort
	for (int i=0; i<2*m; i++) {
		ng[--cnt[g[i].first]] = g[i];
	}
	assert(cnt[0] == 0);
	scanf("%d", &k);
	stack<int> s;
	for (int i=0; i<k; i++) {
		int num;
		scanf("%d", &num);
		s.push(num);
		attacked[num] = true;
	}
	for (int i=0; i<n; i++) {
		if (!attacked[i]) {
			++conn;
			for (int j=cnt[i]; j<cnt[i+1]; j++) {
				assert(ng[j].first == i);
				if (!attacked[ng[j].second]) {
					_union(i, ng[j].second);
				}
			}
		}
	}
	stack<int> res;
	res.push(conn);
	for (int i=0; i<k; i++) {
		assert(!s.empty());
		int tp = s.top();
		attacked[tp] = false;
		s.pop();
		++conn;
		for (int j=cnt[tp]; j<cnt[tp+1]; j++) {
			assert(ng[j].first == tp);
			if (!attacked[ng[j].second]) {
				_union(tp, ng[j].second);
			}
		}
		res.push(conn);
	}
	while(!res.empty()) {
		printf("%d\n", res.top());
		res.pop();
	}
	return 0;
}
