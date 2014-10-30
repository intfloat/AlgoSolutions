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

int main() {
	int n, m;
	bool g[105][105];
	memset(g, false, sizeof(g));
	for (int i = 0; i < 105; ++i) g[i][i] = true;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x][y] = true;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				g[j][k] |= g[j][i] && g[i][k];

    int res = 0;
	for (int i = 1; i <= n; ++i) {
		bool ok = true;
		for (int j = 1; j <= n; ++j) {
			ok = ok && (g[i][j] || g[j][i] );
		}
		res += ok;
	}	
	cout << res << endl;	
	return 0;
}
