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

int n;
vector<int> edge[10005];
bool visited[10005], ok[10005];

int dfs(int x) {
	visited[x] = true;
	vector<int>::iterator it = edge[x].begin();
	int s = 0;
	for (; it != edge[x].end(); ++it) {
		if (visited[*it]) continue;		
        int number = dfs(*it);
        if (number * 2 > n) ok[x] = false;
        s += number;
	}
	if ((n - s - 1) * 2 > n) ok[x] = false;
	return s + 1;
}

int main() {
    memset(visited, false, sizeof(visited));
    memset(ok, true, sizeof(ok));
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y); edge[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		if (ok[i]) printf("%d\n", i);
	}
	return 0;
}

