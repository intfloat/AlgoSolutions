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

const int MAX_M = 13000;
int main() {
	int n, m, dp[MAX_M];
	scanf("%d%d", &n, &m);
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; ++i) {
		int w, d;
		scanf("%d%d", &w, &d);
		for (int j = m; j >= w; --j) dp[j] = max(dp[j], dp[j - w] + d);
	}
	printf("%d\n", dp[m]);
	return 0;
}
