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

const int MAX_N = 305;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> wei;
	vector<pair<int, int> > g[MAX_N];
	for (int i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		g[x].push_back(make_pair(y, w));
		g[y].push_back(make_pair(x, w));
		wei.push_back(w);
	}	
	sort(wei.begin(), wei.end());
	int left = 0, right = static_cast<int>(wei.size()) - 1;
	while (left < right) {
		// cout << left << " " << right << endl;
		// breadth first search
		int mid = (left + right) / 2;
		vector<bool> visited(MAX_N, false);
		// assert(visited.size() == MAX_N);
		queue<int> q;
		q.push(1); visited[1] = true;
		while (!q.empty()) {
			int tp = q.front(); q.pop();
			for (int i = 0; i < g[tp].size(); ++i) {
				if (visited[g[tp][i].first] || g[tp][i].second > wei[mid]) continue;
				q.push(g[tp][i].first);
				visited[g[tp][i].first] = true;
			}
		}
		int cnt = accumulate(visited.begin(), visited.end(), 0);
		// cout << wei[mid] << " " << cnt << endl;
		if (cnt == n) right = mid;
		else left = mid + 1;
	}
	cout << n - 1 << " " << wei[left] << endl;
	return 0;
}
