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

struct edge {
   int to;
   int wei;
   bool train;
   edge(int _to, int _wei, bool _train): to(_to), wei(_wei), train(_train) {}
};

int main() {
	int n, m, k;
	map<int, vector<edge> > g;
	bool visited[100005];
	memset(visited, false, sizeof(visited));
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i<m; i++) {
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		if (g.find(u) == g.end()) {
			vector<edge> s; s.clear(); g[u] = s;
		}
		edge e(v, x, false);
		g[u].push_back(e);
		if (g.find(v) == g.end()) {
			vector<edge> s; s.clear(); g[v] = s;
		}
		g[v].push_back(edge(u, x, false));
	}
	if (g.find(1) == g.end()) {
		vector<edge> s; s.clear(); g[1] = s;
	}
	for(int i=0; i<k; i++) {
		int v, x;
		scanf("%d%d", &v, &x);
		g[1].push_back(edge(v, x, true));
	}

	vector<pair<int, pair<int, bool> > > hp;
	
	vector<pair<int, bool> > v;
	for(int i=0; i<=n; i++) v.push_back(make_pair(INT_MAX/2, false));
    v[1].first = 0;

	hp.push_back(make_pair(0, make_pair(1, false)));
	for (int i=2; i<=n; i++) hp.push_back(make_pair(INT_MIN/2, make_pair(i, false)));
	make_heap(hp.begin(), hp.end());
	pair<int, pair<int, bool> > tm;
	int ans = 0;
	for(int i=0; i<n; i++) {
		while(true) {
			tm = hp.front();
			pop_heap(hp.begin(), hp.end());			
			hp.pop_back();
			if (hp.front().first == tm.first 
				&& hp.front().second.first==tm.second.first
				&& tm.second.second
				) {
				continue;
			}
			if (visited[tm.second.first]) continue;
			else break;
		}
		if (tm.second.second) ++ans;
		int index = tm.second.first;
		visited[index] = true;
		vector<edge>::iterator it;
		int dis = -tm.first;
		for(it = g[index].begin(); it!=g[index].end(); ++it) {
			edge cur = *it;
			if(dis+cur.wei < v[cur.to].first) {
				v[cur.to].first = dis + cur.wei;
				v[cur.to].second = cur.train;
				hp.push_back(make_pair(-v[cur.to].first, make_pair(cur.to, v[cur.to].second)));
				push_heap(hp.begin(), hp.end());
			}
			else if(dis+cur.wei==v[cur.to].first && v[cur.to].second && !cur.train) {
				v[cur.to].second = cur.train;
				hp.push_back(make_pair(-v[cur.to].first, make_pair(cur.to, v[cur.to].second)));
				push_heap(hp.begin(), hp.end());
			}
		}
	}
	ans = k-ans;
	printf("%d\n", ans);
	return 0;
}
