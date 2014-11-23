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

const int MAX_N = 100005;
const int MOD = 1000000007;
int n;
vector<int> g[MAX_N];
int color[MAX_N];
bool visited[MAX_N];

int main(){		
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int x;
		scanf("%d", &x);
		g[i + 1].push_back(x); g[x].push_back(i + 1);
	}
	int pos = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", color + i);
		if (color[i] == 1) pos = i;
	}
	assert(pos >= 0);
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(pos); visited[pos] = true;
	int last = -1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (color[cur] == 1) last = cur;
		int len = g[cur].size();
		for (int i = 0; i < len; ++i) {
			int index = g[cur][i];
			if (!visited[index]) {
				visited[index] = true;
				q.push(index);
			}
		}
	}
	assert(last >= 0);
	memset(visited, false, sizeof(visited));
	queue<pair<int, int> > mq;
	int dis[MAX_N];
	dis[last] = 0;
	mq.push(make_pair(last, last));
	visited[last] = true;
	long long res = 1;
	while (!mq.empty()) {
		pair<int, int> cur = mq.front(); mq.pop();
		int len = g[cur.first].size();
		for (int i = 0; i < len; ++i) {
			int index = g[cur.first][i];
			if (visited[index]) continue;
			visited[index] = true;
			dis[index] = dis[cur.first] + 1;
			if (color[index] == 1) {
				mq.push(make_pair(index, index));
				res = (res * (dis[index] - dis[cur.second])) % MOD;
			}
			else {
				mq.push(make_pair(index, cur.second));
			}
		}
	}
	cout << res << endl;
	return 0;
}

