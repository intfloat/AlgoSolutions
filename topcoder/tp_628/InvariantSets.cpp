#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

using namespace std;

const int MAX_N = 55;
bool g[MAX_N][MAX_N];
int n;
int scc[MAX_N];
bool visited[MAX_N];
long long res;
long long dp[MAX_N];
bool ng[MAX_N][MAX_N];
int p[MAX_N], conn;

class InvariantSets {
public:
	long long countSets(vector <int>);
	void dfs(int pos) {
		visited[pos] = true;
		scc[pos] = conn;
		for (int i = 0; i < n; ++i) {
			if (!visited[i] && g[i][pos] && g[pos][i]) {
				dfs(i);
			}
		}
		return;
	}

	long long get(int pos) {
		if (dp[pos] > 0) return dp[pos];	
		long long cur = 1;
		for (int i = 0; i < conn; ++i) {
			if (ng[pos][i]) cur = cur * get(i);
		}
		dp[pos] = 1 + cur;
		return dp[pos];
	}
};

long long InvariantSets::countSets(vector <int> f) {	
	memset(g, false, sizeof(g));
	n = f.size();
	for (int i = 0; i < n; ++i) g[f[i]][i] = true;
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	for (int k = 0; k < n; ++k) {
		g[j][k] = g[j][k] || (g[j][i] && g[i][k]);
	}	
	memset(visited, false, sizeof(visited));	
	conn = 0;
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs(i);
			++conn;
		}
	}
	memset(ng, false, sizeof(ng));	
	for (int i = 0; i < n; ++i) p[i] = -1;
	for (int i = 0; i < n; ++i) {
		int x = scc[f[i]];
		int y = scc[i];
		if (x == y) continue;
		ng[x][y] = true;
		p[y] = x;
	}	
	res = 1;
	memset(dp, 0, sizeof(dp));	
	for (int i = 0; i < conn; ++i) {
		if (dp[i] == 0) {
			dp[i] = get(i);
			if (p[i] < 0) res = res * dp[i];
		}
	}
	return res;
}


//Powered by [KawigiEdit] 2.0!