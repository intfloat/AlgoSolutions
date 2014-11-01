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

typedef long long ll;
vector<pair<int, int> > ps;

ll sq(int p1, int p2) {
	--p1; --p2;
	return (ll)(ps[p2].first - ps[p1].first) * (ps[p2].first - ps[p1].first) 
	           + (ll)(ps[p2].second - ps[p1].second) * (ps[p2].second - ps[p1].second);
}

int main() {
	int n, m;
	ll dis[1005];
	vector<int> g[1005];
	bool visited[1005];
	memset(visited, false, sizeof(visited));
	scanf("%d%d", &n, &m);
	int x, y;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		ps.push_back(make_pair(x, y));
	}
	for (int i = 0; i < m; ++i) {		
		scanf("%d%d", &x, &y);
		g[x].push_back(y); g[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) dis[i] = (ll)1e14;
	dis[1] = 0;
	double res = 0;

	for (int i = 0; i < n; ++i) {		
		int pos = -1;
		long long mn = (ll)1e14;
		for (int j = 1; j <= n; ++j) {
			if (!visited[j] && dis[j] < mn) { mn = dis[j]; pos = j; }
		}
		if (pos < 0) break;
		visited[pos] = true;
		res += sqrt(dis[pos]);
		// cout << pos << " " << sqrt(dis[pos]) << endl;
		for (int j = 1; j <= n; ++j) {
			if (!visited[j]) dis[j] = min(dis[j], sq(j, pos));
		}
		queue<int> q;
		q.push(pos);
		while (!q.empty()) {
			int tp = q.front(); q.pop();
			for (vector<int>::iterator it = g[tp].begin(); it != g[tp].end(); ++it) {
				if (visited[*it]) continue;
				visited[*it] = true;
				dis[*it] = min(dis[*it], dis[tp] + sq(tp, *it));
				for (int j = 1; j <= n; ++j) {
					if (!visited[j]) dis[j] = min(dis[j], sq(j, *it));
				}
				q.push(*it);
			}
		} // end while loop
	}
	cout << fixed << setprecision(2) << res << endl;
	return 0;
}
