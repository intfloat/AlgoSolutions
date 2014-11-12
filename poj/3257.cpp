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

const int MAX_N = 1005;
struct Node {
	int begin, end, cost, fun;
	Node(int _b, int len, int _c, int _f): begin(_b), end(_b + len), cost(_c), fun(_f) {}	
};

bool cmp(const Node& n1, const Node& n2) { return n1.end < n2.end; }

int main() {
	int L, N, B;
	int dp[MAX_N][MAX_N];
	cin >> L >> N >> B;
	vector<Node> v;
	for (int i = 0; i < N; ++i) {
		int x, w, f, c;
		cin >> x >> w >> f >> c;
		v.push_back(Node(x, w, c, f));
	}
	sort(v.begin(), v.end(), cmp);
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < v.size(); ++i) {
		int s = v[i].begin;
		int e = v[i].end;
		for (int j = v[i].cost; j <= B; ++j) {
			if (s == 0) dp[j][e] = max(dp[j][e], dp[j - v[i].cost][s] + v[i].fun);
			else if (dp[j - v[i].cost][s] > 0) dp[j][e] = max(dp[j][e], dp[j - v[i].cost][s] + v[i].fun);
		}
	}
	if (dp[B][L] > 0) cout << dp[B][L] << endl;
	else cout << -1 << endl;
	return 0;
}
