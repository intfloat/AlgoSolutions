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

int main() {
	int K, N, M, t;
	vector<int> cows, g[1005];
	cin >> K >> N >> M;
	for (int i = 0; i < K; ++i) { cin >> t; cows.push_back(t); }
	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}
	bool visited[1005];	
	int cnt[1005];
	memset(cnt, 0, sizeof(cnt));

	queue<int> q;
	for (int i = 0; i < K; ++i) {
		memset(visited, false, sizeof(visited));
		q.push(cows[i]); visited[cows[i]] = true;
		while (!q.empty()) {
			int tp = q.front(); q.pop();
			for (vector<int>::iterator it = g[tp].begin(); it != g[tp].end(); ++it) {
				if (visited[*it]) continue;
				visited[*it] = true;
				q.push(*it);
			}
		}
		for (int i = 1; i <= N; ++i) cnt[i] += visited[i];
	}
	
	int res = 0;
	for (int i = 1; i <= N; ++i) { res += (cnt[i] == K); }
	cout << res << endl;
	return 0;
}
