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

const int MOD = 1000;
int main() {
	int t;
	long long k;
	cin >> t;
	while (t--) {
		cin >> k;
		int n = 0, m = 0;
		int mp[MOD + 5];
		for (int i = 0; i < MOD+5; ++i) mp[i] = -1;
		long long cur = 1;
		bool begin = false;
		while (true) {
			if (!begin) {
				if (cur >= MOD) { begin = true; }
				else { cur = cur * k; ++n; continue; }
			}
			if (mp[cur % MOD] >= 0) {
				m = n;
				n = mp[cur % MOD];
				break;
			}			
			mp[cur % MOD] = n;
			++n;
			cur = (cur * k) % MOD;
		}
		cout << m + n << endl;
	}
	return 0;
}
