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
	int T, N, res, city, P;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		cin >> N;
		vector<pair<int, int> > v;
		int x, y;
		FOR(i, N) { cin >> x >> y; v.push_back(make_pair(x, y)); }
		cin >> P;
		cout << "Case #" << tt << ":";
		FOR(i, P) {
			cin >> city;
			res = 0;
			FOR(j, v.size()) res += (city >= v[j].first && city <= v[j].second);
			cout << " " << res;
		}
		cout << endl;
	}
	return 0;
}
