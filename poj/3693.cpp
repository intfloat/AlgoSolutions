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

const int maxn = 100005;
// auxiliary array
int wb[maxn], wv[maxn], wss[maxn];
int n, r[maxn], sa[maxn], rank[maxn], h[maxn];
string s;

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

/*
 * r is an array
 * sa is an array storing result
 * n is length of r
 * m is radix
 */
void da(int *r, int *sa, int n, int m) {
    int i, j, p, *x = rank, *y = wb, *t;
    for (i = 0; i < m; ++i) wss[i] = 0;
    for (i = 0; i < n; ++i) wss[x[i] = r[i]]++;
    for (i = 1; i < m; ++i) wss[i] += wss[i - 1];
    for (i = n - 1; i >= 0; --i)
       sa[--wss[x[i]]] = i;

    for (j = 1, p = 1; p < n; j *= 2, m = p) {
        for (p = 0, i = n - j; i < n; ++i) y[p++] = i;
        for (i = 0; i < n; ++i) if(sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < n; ++i) wv[i] = x[y[i]];
        for (i = 0; i < m; ++i) wss[i] = 0;
        for (i = 0; i < n; ++i) wss[wv[i]]++;
        for (i = 1; i < m; ++i) wss[i] += wss[i - 1];
        for (i = n - 1; i >= 0; --i) sa[--wss[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; ++i)
        x[sa[i]] = cmp(y, sa[i - 1], sa[i], j)? p - 1 : p++;
    }
    return;
}

void height() {
	int j, k = 0;
	for (int i = 1; i <= n; ++i) rank[sa[i]] = i;
	for (int i = 0; i < n; ++i) {
		for (k > 0? k--:0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; ++k);
		h[rank[i]] = k;
	}
	return;
}

int rmq[maxn][18];
void rmq_init() {
	for (int i = 1; i <= n; ++i) rmq[i][0] = h[i];
	for (int p = 1; (1 << p) <= n; ++p) {
		for (int i = 1; i + (1 << p) <= n; ++i)
			rmq[i][p] = min(rmq[i][p - 1], rmq[i + (1 << (p - 1))][p - 1]);
	}
	return;
}

// longest common prefix
int lcp(int x, int y) {
	int rx = rank[x];
	int ry = rank[y];
	if (rx > ry) swap(rx, ry);
	++rx;
	int pw = 0;
	while ((1 << (pw + 1)) < (ry - rx + 1)) ++pw;
	int res = min(rmq[rx][pw], rmq[ry - (1 << pw) + 1][pw]);
	// cout << "lcp " << x << " " << y << ": " << res << endl;
	return res;
}

// ccabababc
int main() {
	int t = 1;
	while (cin >> s && s != "#") {
		n = s.size();
        for(int i = 0; i < n; ++i) r[i] = s[i] - 'a' + 1;
        r[n] = 0;
        da(r, sa, n + 1, 27);
        height();
        // for (int i = 1; i <= n; ++i) cout << h[i] << endl;
        rmq_init();
        set<int> vlen;
        int tlen, mx = -1;
        for (int len = 1; len <= n; ++len) {
        	for (int i = 0; i + len < n; i += len) {
        		int cur = lcp(i, i + len);
        		int rep = cur / len + 1;
        		int st = i - (len - cur % len);
        		if (st >= 0 && (cur % len > 0)) rep = max(rep, lcp(st, st + len) / len + 1);
        		if (rep > mx) { mx = rep; tlen = len; vlen.clear(); vlen.insert(len); }
        		else if (rep == mx) { vlen.insert(len); }
        	}
        }

        // cout << "target length: " << tlen << endl;
        // cout << "max rep: " << mx << endl;
        // for (set<int>::iterator it = vlen.begin(); it != vlen.end(); ++it) {
        	// cout << "possible length: " << *it << endl;
        // }
        bool ok = false;
        for (int i = 1; i <= n && !ok; ++i) {
        	for (set<int>::iterator it = vlen.begin(); it != vlen.end(); ++it) {
        		int index = sa[i];        		
        		// cout << s.substr(index, n - index) << endl;
        		if (index + *it * mx <= n && (lcp(index, index + *it) / *it + 1) == mx) {
        			cout << "Case " << t++ << ": " << s.substr(index, *it * mx) << endl;
        			ok = true;
        			break;
        		}
        	}
        }

	}
	return 0;
}
