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

int n, p, k;
vector<pair<int, int> > g[1005];
vector<pair<int, int> > gt[1005];
bool connected = true;

bool spfa(int t) {
	for (int i = 1; i <= n; ++i)
	for (int j = 0; j < g[i].size(); ++j)
		gt[i][j].second = (g[i][j].second > t);
	bool visited[1005];
	memset(visited, false, sizeof(visited));
	queue<int> q;
	int dis[1005];
	for (int i = 1; i <= n; ++i) dis[i] = INT_MAX / 2;
	q.push(1); visited[1] = true; dis[1] = 0;
	while (!q.empty()) {
		int tp = q.front(); q.pop(); visited[tp] = false;
		for (vector<pair<int, int> >::iterator it = gt[tp].begin(); it != gt[tp].end(); ++it) {
			int pos = (*it).first; int wei = (*it).second;
			if (dis[pos] > dis[tp] + wei) {
				dis[pos] = dis[tp] + wei;
				if (!visited[pos]) { q.push(pos); visited[pos] = true; }
			}
		}
	}
	if (dis[n] == INT_MAX / 2) connected = false;
	// cout << t << endl;
	return (dis[n] <= k);
}

int main() {
	cin >> n >> p >> k;
	int left = 0, right = 0;
	for (int i = 0; i < p; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		g[x].push_back(make_pair(y, w)); g[y].push_back(make_pair(x, w));
		gt[x].push_back(make_pair(y, 0)); gt[y].push_back(make_pair(x, 0));
		right = max(right, w);
	}
	while (left < right) {
		int mid = (left + right) / 2;		
		if (spfa(mid)) right = mid;
		else left = mid + 1;
		if (!connected) { cout << -1 << endl; return 0; }
	}
	cout << left << endl;
    return 0;
}
