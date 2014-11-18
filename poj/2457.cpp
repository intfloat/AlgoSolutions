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

const int MAX_N = 1005;
int main() {
	vector<int> g[MAX_N];
	int N, K, res[MAX_N], pathTo[MAX_N];
	cin >> N >> K;
	FOR(i, N) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}
	bool visited[MAX_N];
	memset(visited, false, sizeof(visited));
	FOR(i, MAX_N) { res[i] = INT_MAX / 2; pathTo[i] = -1; }
	visited[1] = true; res[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int tp = q.front(); q.pop();
		if (tp == K) break;
		FOR(i, g[tp].size()) {
			int index = g[tp][i];
			if (visited[index]) continue;
			visited[index] = true; res[index] = res[tp] + 1; pathTo[index] = tp;
			q.push(index);
		}
	}
	vector<int> p;
	int prev = K;
	while (prev != -1) { p.push_back(prev); prev = pathTo[prev]; }
	reverse(p.begin(), p.end());
	if (!visited[K]) { cout << -1 << endl; return 0; }
	cout << p.size() << endl;	
	FOR(i, p.size()) cout << p[i] << endl;
	return 0;
}
