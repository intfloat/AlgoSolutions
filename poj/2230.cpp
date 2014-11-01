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

const int MAX_N =600005;
int head[10005], next[MAX_N], pnt[MAX_N], visited[MAX_N];
int ptr = 0;

void add(int u, int v) {
	pnt[ptr] = v; next[ptr] = head[u]; head[u] = ptr++;
}

void euler(int u) {
	for (int i = head[u]; i >= 0; i = next[i]) {
		if (!visited[i]) {
			visited[i] = true;
			euler(pnt[i]);
		}
	}
	printf("%d\n", u);
}

int main() {
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	memset(visited, false, sizeof(visited));
	for (int i = 0; i <= n; ++i) head[i] = -1;
	for (int i = 0; i < m; ++i) {		
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	euler(1);
	return 0;
}
