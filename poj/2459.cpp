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
	int c, f1, f2, d;
	cin >> c >> f1 >> f2 >> d;
	pair<int, int> cows[105];
	FOR(i, c) cin >> cows[i].first >> cows[i].second;
	int total = 0;
	for (int i = d; i >= 0; --i) {
		FOR(j, c) total += (cows[j].first <= i) && (cows[j].second >= i);
		if (total >= f1 - f2) { cout << i << endl; return 0; }
	}
	assert(false);
	return 0;
}
