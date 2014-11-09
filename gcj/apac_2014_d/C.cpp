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

int main() {
	int T, N;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		cin >> N;
		map<string, string> g;
		map<string, int> cnt;
		FOR(i, N) {
			string from, to;
			cin >> from >> to;
			g[from] = to;
			if (cnt.find(from) == cnt.end()) cnt[from] = 0;			
			if (cnt.find(to) == cnt.end()) cnt[to] = 1;
			else ++cnt[to];
		}
		string s = "";
		for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
			if ((it->second) == 0) { s = it->first; break; }
		}
		assert(s != "");
		cout << "Case #" << tt << ":";
		while (g.find(s) != g.end()) { cout << " " << s << "-" << g[s]; s = g[s]; }
		cout << endl;
	}
	return 0;
}

