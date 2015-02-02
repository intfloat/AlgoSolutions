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
#include <sstream>

using namespace std;

const int MAXN = 40005;
vector<int> g[MAXN];
int n, parent[MAXN], hson[MAXN], head[MAXN];
// the position of current vertex in segment tree
int mp[MAXN], dep[MAXN], son_cnt[MAXN], wei[MAXN];

struct Node {
	// [left, right] interval
    int l, r, pl, pr;
    int s, mx_val;       
    Node(): pl(0), pr(0), l(0), r(0) {}
};

Node tree[MAXN * 6];
int ptr = 1;
int tr_pos = 1;

struct Rec {
    int cur, prev, d;
    bool first;
    Rec(int _cur, int _prev, int _d): cur(_cur), prev(_prev), d(_d), first(true) {}
};
void dfs1(int _cur, int _prev, int _d) {	
	// use nonrecursive implementation to avoid stack overflow, danteng...
	stack<Rec> s;
	s.push(Rec(_cur, _prev, _d));
	while (!s.empty()) {
		Rec t = s.top(); s.pop();
		if (t.first) {
			parent[t.cur] = t.prev;
			dep[t.cur] = t.d;
			son_cnt[t.cur] = 1;
			hson[t.cur] = -1;
			t.first = false;
			s.push(t);
			vector<int>::iterator it = g[t.cur].begin();
			for (; it != g[t.cur].end(); ++it) {
				if (*it == t.prev) continue;
				s.push(Rec(*it, t.cur, t.d + 1));
			}
		}
		else {			
			son_cnt[t.prev] += son_cnt[t.cur];
			if (hson[t.prev] < 0 || son_cnt[t.cur] > son_cnt[hson[t.prev]]) {
				hson[t.prev] = t.cur;
			}
		}
	}
	return;
	/* parent[cur] = prev;
	dep[cur] = d;
	son_cnt[cur] = 1;	
	vector<int>::iterator it = g[cur].begin();
	int mx = -1;
	// int index = -1;
	for (; it != g[cur].end(); ++it) {
		// cout << "cur: " << cur << " tag4: " << *it << endl;
        if (prev == *it) continue;
        dfs1(*it, cur, d + 1);
        son_cnt[cur] += son_cnt[*it];
        if (son_cnt[*it] > mx) {
        	mx = son_cnt[*it];
        	hson[cur] = *it;
        }
	}
	if (mx == -1) hson[cur] = -1;
	return; */
}

struct Rec2 {
    int cur, prev;
    bool first;
    Rec2(int _cur, int _prev): cur(_cur), prev(_prev), first(true) {}
};

void dfs2(int cur, int prev) {
	// use nonrecursive implementation to avoid stack overflow, danteng...
	stack<Rec2> s;
	s.push(Rec2(cur, prev));
	while (!s.empty()) {
		Rec2 t = s.top(); s.pop();
		if (t.first) {
			mp[t.cur] = ptr++;
			if (hson[t.cur] < 0) continue;
			head[hson[t.cur]] = head[t.cur];
			t.first = false;
			s.push(t);
			vector<int>::iterator it = g[t.cur].begin();
			for (; it != g[t.cur].end(); ++it) {
				if ((*it == t.prev) || (*it == hson[t.cur])) continue;
				head[*it] = *it;
				s.push(Rec2(*it, t.cur));
			}
			s.push(Rec2(hson[t.cur], t.cur));			
		}		
	}
	return;

	/*mp[cur] = ptr++;
	// a leaf node
	if (hson[cur] < 0) {		
	    return;
	}
	vector<int>::iterator it = g[cur].begin();
	// first traverse heavy son to ensure continuation
	head[hson[cur]] = head[cur];
	dfs2(hson[cur], cur);	
	for (; it != g[cur].end(); ++it) {
		if ((*it == prev) || (*it == hson[cur])) continue;
		head[*it] = *it;
		dfs2(*it, cur);
	}
	return;*/
}

void build_tree(int i, int left, int right) {
    if (left == right) {
        tree[i].l = left; tree[i].r = right;
        // tree[i].mx_val = tree[i].s = wei[left];
        return;        
    }
    int mid = (left + right) / 2;
    tree[i].pl = tr_pos++;
    build_tree(tree[i].pl, left, mid);
    tree[i].pr = tr_pos++;
    build_tree(tree[i].pr, mid + 1, right);
    tree[i].l = left; tree[i].r = right;
    // tree[i].mx_val = max(tree[tree[i].pl].mx_val, tree[tree[i].pr].mx_val);
    // tree[i].s = tree[tree[i].pl].s + tree[tree[i].pr].s;
    return;
}

void update(int i, int pos, int val) {
	if (tree[i].l == pos && tree[i].r == pos) {
		tree[i].mx_val = tree[i].s = val;
		return;
	}
	// assert(pos >= tree[i].l && pos <= tree[i].r);
	int mid = (tree[i].l + tree[i].r) / 2;
	if (pos <= mid) update(tree[i].pl, pos, val);			
	else update(tree[i].pr, pos, val);
	tree[i].mx_val = max(tree[tree[i].pl].mx_val, tree[tree[i].pr].mx_val);
    tree[i].s = tree[tree[i].pl].s + tree[tree[i].pr].s;
    return;
}

int query_mx(int i, int left, int right) {
    if (tree[i].l == left && tree[i].r == right) return tree[i].mx_val;
    int mid = (tree[i].l + tree[i].r) / 2;
    if (right <= mid) return query_mx(tree[i].pl, left, right);
    else if (left > mid) return query_mx(tree[i].pr, left, right);
    else return max(query_mx(tree[i].pl, left, mid), query_mx(tree[i].pr, mid + 1, right));
}

int query_sum(int i, int left, int right) {
    if (tree[i].l == left && tree[i].r == right) return tree[i].s;
    int mid = (tree[i].l + tree[i].r) / 2;
    if (right <= mid) return query_sum(tree[i].pl, left, right);
    else if (left > mid) return query_sum(tree[i].pr, left, right);
    else return query_sum(tree[i].pl, left, mid) + query_sum(tree[i].pr, mid + 1, right);
}

int main() {
    // freopen("bzoj_1036.in", "r", stdin);
    // freopen("bzoj_1036.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y); g[y].push_back(x);		
	}
	for (int i = 1; i <= n; ++i) scanf("%d", wei + i);
	memset(son_cnt, 0, sizeof(son_cnt));    
    dfs1(1, 0, 0);
    // need to ensure first node's head was set
    head[1] = 1;    
    dfs2(1, 1);    
    tr_pos = 2;
    build_tree(1, 1, n);
    // initialize value of segment tree
    for (int i = 1; i <= n; ++i) update(1, mp[i], wei[i]);
    
    int q;
    scanf("%d", &q);
    while (q--) {
    	string cmd;
        char tmp[30];
        int x, y;
        scanf("%s %d %d", tmp, &x, &y);
        cmd = tmp;    	
    	if (cmd == "CHANGE") update(1, mp[x], y);
    	// query maximum value
    	else if (cmd == "QMAX") {
    		int res = INT_MIN;
    		int h1 = head[x]; int h2 = head[y];    		
    		while (h1 != h2) {    			
    			if (dep[h1] > dep[h2]) {
    				// assert(mp[h1] <= mp[x]);
    				res = max(res, query_mx(1, mp[h1], mp[x]));
    				x = parent[h1];
    			}
    			else {
    				// assert(mp[h2] <= mp[y]);
    				res = max(res, query_mx(1, mp[h2], mp[y]));
    				y = parent[h2];
    			}
    			h1 = head[x]; h2 = head[y];
    		}
    		// if (mp[x] > [y]) res = max(res, query_mx(1, mp[h1], mp[x]));
    		res = max(res, query_mx(1, min(mp[x], mp[y]), max(mp[x], mp[y])));
    		printf("%d\n", res);
    	}
    	// query sum on a specific path
    	else if (cmd == "QSUM") {
    	    int res = 0;
    		int h1 = head[x]; int h2 = head[y];
    		while (h1 != h2) {
    			if (dep[h1] > dep[h2]) {
    				// assert(mp[h1] <= mp[x]);
    				res += query_sum(1, mp[h1], mp[x]);
    				x = parent[h1];
    			}
    			else {
    				// assert(mp[h2] <= mp[y]);
    				res += query_sum(1, mp[h2], mp[y]);
    				y = parent[h2];
    			}
    			h1 = head[x]; h2 = head[y];
    		}    		
    		// if (dep[x] > dep[y]) res += query_mx(1, mp[h1], mp[x]);
    		res += query_sum(1, min(mp[x], mp[y]), max(mp[x], mp[y]));
    		printf("%d\n", res);	
    	}
    	// impossible to reach here
    	// else assert(0 == 1);
    }
	return 0;
}
