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

const int MAX_N = 305;
const int INF = INT_MAX / 2;
const int dir_x[] = {0, 0, -1, 1};
const int dir_y[] = {-1, 1, 0, 0};

int main() {
	int M, dt[MAX_N][MAX_N], ans[MAX_N][MAX_N];
	bool visited[MAX_N][MAX_N];
	memset(visited, false, sizeof(visited));
	FOR(i, MAX_N) FOR(j, MAX_N) { dt[i][j] = INF; ans[i][j] = INF; }
	cin >> M;
	FOR(i, M) {
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		dt[x][y] = min(dt[x][y], t);
		FOR(j, 4) {
			int nx = x + dir_x[j], ny = y + dir_y[j];
			if (nx < 0 || ny < 0) continue;
			dt[nx][ny] = min(dt[nx][ny], t);
		}
	}

	if (dt[0][0] == INF) { cout << 0 << endl; return 0; }
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0)); visited[0][0] = true; ans[0][0] = 0;	
	while (!q.empty()) {
		pair<int, int> tp = q.front(); q.pop();
		FOR(i, 4) {
			int nx = tp.first + dir_x[i], ny = tp.second + dir_y[i];
			if (nx < 0 || ny < 0) continue;
			if (visited[nx][ny]) continue;
			if (dt[nx][ny] <= ans[tp.first][tp.second] + 1) continue;
			visited[nx][ny] = true; ans[nx][ny] = ans[tp.first][tp.second] + 1;
			if (dt[nx][ny] == INF) { cout << ans[nx][ny] << endl; return 0; }
			else q.push(make_pair(nx, ny));
		}
	}
	cout << -1 << endl;
	return 0;
}
