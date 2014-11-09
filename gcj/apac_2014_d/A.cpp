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
int dp[MAX_N][MAX_N], arr[MAX_N][MAX_N];
const int dir_x[] = {0, 0, -1, 1};
const int dir_y[] = {1, -1, 0, 0};
int S;
int solve(int x, int y) {
	if (dp[x][y] > 0) return dp[x][y];
	dp[x][y] = 1;
	FOR(k, 4) {
		int xx = x + dir_x[k], yy = y + dir_y[k];
		if (xx < 0 || yy < 0 || xx >= S || yy >= S) continue;
		if (arr[x][y] + 1 != arr[xx][yy]) continue;
		dp[x][y] = max(dp[x][y], solve(xx, yy) + 1);
	}
	return dp[x][y];
}
int main() {
	int T;
	cin >> T;	
	for (int tt = 1; tt <= T; ++tt) {
		cin >> S;
		FOR(i, S) FOR(j, S) { cin >> arr[i][j]; dp[i][j] = 0; }
		int mx = -1, pos = -1;
		FOR(i, S) FOR(j, S) {
			solve(i, j);
			if (dp[i][j] > mx) { mx = dp[i][j]; pos = arr[i][j]; }
			else if (dp[i][j] == mx && arr[i][j] < pos) pos = arr[i][j];
		}
		cout << "Case #" << tt << ": " << pos << " " << mx << endl;
	}
	return 0;
}
