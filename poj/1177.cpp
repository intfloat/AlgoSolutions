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

struct Node {
	int left, right, lc, rc, cnt, total, hcnt;
	bool top, bottom;
	Node() { left = right = lc = rc = -1; cnt = total = hcnt = 0; top = bottom = false; }
};
int ptr = 0;
Node tree[40005];

struct Line {
	int x, y1, y2;
	bool left;
	Line(int _x, int _y1, int _y2, bool _left): x(_x), y1(_y1), y2(_y2), left(_left) {}
};

bool cmp(const Line& n1, const Line& n2) { return n1.x < n2.x; }

void build_tree(int low, int up, int root) {
	tree[root].left = low;
	tree[root].right = up;
	if (up - low <= 1) return;
	int mid = (low + up) / 2;
	++ptr; tree[root].lc = ptr;
	build_tree(low, mid, ptr);
	++ptr; tree[root].rc = ptr;
	build_tree(mid, up, ptr);
	return;
}

void update_node(int root) {
	if (tree[root].cnt > 0) {
		tree[root].total = tree[root].right - tree[root].left;
		tree[root].top = tree[root].bottom = true;
		tree[root].hcnt = 2;
		return;
	}
	if (tree[root].right - tree[root].left <= 1) {
		tree[root].total = 0;
		tree[root].top = tree[root].bottom = false;
		tree[root].hcnt = 0;
	}
	else {
		int lchild = tree[root].lc;
		int rchild = tree[root].rc;
		tree[root].total = tree[lchild].total + tree[rchild].total;
		if (tree[lchild].top) tree[root].top = true; else tree[root].top = false;
		if (tree[rchild].bottom) tree[root].bottom = true; else tree[root].bottom = false;
		tree[root].hcnt = tree[lchild].hcnt + tree[rchild].hcnt;
		if (tree[lchild].bottom && tree[rchild].top) tree[root].hcnt -= 2;
	}
	return;
}

void insert_node(int low, int up, int root) {
	if (low <= tree[root].left && up >= tree[root].right) {		
		++tree[root].cnt;		
		update_node(root);
		return;
	}	
	assert(tree[root].right - tree[root].left > 1);
	int mid = (tree[root].right + tree[root].left) / 2;
	if (up <= mid) insert_node(low, up, tree[root].lc);
	else if (low >= mid) insert_node(low, up, tree[root].rc);
	else {
		insert_node(low, mid, tree[root].lc);
		insert_node(mid, up, tree[root].rc);
	}
	update_node(root);
	return;
}

void delete_node(int low, int up, int root) {
	if (low <= tree[root].left && up >= tree[root].right) {		
		assert(tree[root].cnt > 0);
		--tree[root].cnt;
		update_node(root);
		return;
	}
	assert(tree[root].right - tree[root].left > 1);
	int mid = (tree[root].right + tree[root].left) / 2;
	if (up <= mid) delete_node(low, up, tree[root].lc);
	else if (low >= mid) delete_node(low, up, tree[root].rc);
	else {
		delete_node(low, mid, tree[root].lc);
		delete_node(mid, up, tree[root].rc);
	}
	update_node(root);
	return;	
}

vector<Line> lines;
int main() {
	int N, maxy = INT_MIN, miny = INT_MAX;
	cin >> N;
	if (N == 0) { cout << 0 << endl; return 0; }
	for (int i = 0; i < N; ++i) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		lines.push_back(Line(x1, y1, y2, true));
		lines.push_back(Line(x2, y1, y2, false));
		maxy = max(maxy, max(y1, y2));
		miny = min(miny, min(y1, y2));
	}
	sort(lines.begin(), lines.end(), cmp);
	build_tree(miny, maxy, 0);
	int res = 0, prev = 0;
	for (int i = 0; i < lines.size(); ++i) {
		if (lines[i].left) insert_node(lines[i].y1, lines[i].y2, 0);
		else delete_node(lines[i].y1, lines[i].y2, 0);
		res += abs(prev - tree[0].total);
		prev = tree[0].total;
		if (i + 1 < lines.size())
			res += tree[0].hcnt * (lines[i + 1].x - lines[i].x);
	}	
	cout << res << endl;
	return 0;
}
