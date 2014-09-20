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

const int MAX_N = (1 << 16);
int dp[MAX_N];
bool visited[MAX_N];
const int dir[] = {-1, 1, 4, -4};
int main() {
	string s, t;
	int begin = 0, end = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> s;
		// assert(s.size() == 4);
		for (int j = 0; j < 4; ++j) 
			begin = (begin << 1) + (s[j] - '0');		
	}
	for (int i = 0; i < 4; ++i) {
		cin >> t;
		// assert(t.size() == 4);
		for (int j = 0; j < 4; ++j) 
			end = (end << 1) + (t[j] - '0');		
	}
	memset(visited, false, sizeof(visited));
	dp[begin] = 0; visited[begin] = true;

	queue<int> q;
	q.push(begin);
	while (!q.empty() && !visited[end]) {
		int tp = q.front(); q.pop();
		// cout << tp << " 1s: " << __builtin_popcount(tp) << endl;
		for (int i = 15; i >= 0; --i) {
			if ((tp & (1<<i)) == 0) continue;
			for (int j = 0; j < 4; ++j) {
				if ((i + 1) % 4 == 0 && dir[j] == 1) continue;
				if (i % 4 == 0 && dir[j] == -1) continue;
				int pos = i + dir[j];
				if (pos < 0 || pos > 15 || (tp & (1<<pos))) continue;
				int ne = (tp & (~(1<<i)));
				ne |= (1 << pos);
				// assert(__builtin_popcount(ne) == __builtin_popcount(tp));
				if (visited[ne]) continue;
				visited[ne] = true;
				dp[ne] = dp[tp] + 1;
				q.push(ne);
			}
		}
	}
	// assert(visited[end]);
	cout << dp[end] << endl;
	return 0;
}
