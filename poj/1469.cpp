// bipartite graph matching
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

const int MAX_N = 405;
vector<int> g[MAX_N];
bool visited[MAX_N];
int match[MAX_N];

bool dfs(int pos) {	
	visited[pos] = true;
	int len = g[pos].size();
	for (int i = 0; i < len; ++i) {
		int cur = g[pos][i];
		if (visited[cur]) continue;
		visited[cur] = true;
		if (match[cur] == -1 || dfs(match[cur])) {
			match[cur] = pos;
			return true;
		}
	}
	return false;
}

int main() {
	int t, course, stu;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &course, &stu);		
		for (int i = 0; i < MAX_N; ++i) {
			g[i].clear();
			match[i] = -1;
		}
		for (int i = 0; i < course; ++i) {			
			int num, s;
			scanf("%d", &num);
			for (int j = 0; j < num; ++j) {
				scanf("%d", &s);
				g[i].push_back(course + s);
			}
		}

		if (stu < course) { printf("NO\n"); continue; }
		bool ok = true;
		for (int i = 0; i < course; ++i) {
			memset(visited, false, sizeof(visited));
			ok = dfs(i);
			if (!ok) { printf("NO\n"); break; }
		}
		if (ok) printf("YES\n");
	}
	return 0;
}
