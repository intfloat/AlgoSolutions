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

int cnt[10], res, mod;
void dfs(int remain, long long number) {
	if (remain == 0) {
		if ((number % mod) == 0) ++res;
		return;
	}
	for (int i = 0; i < 10; ++i) {
		if (cnt[i]) {
			--cnt[i];
			dfs(remain - 1, number * 10 + i);
			++cnt[i];
		}
	}
	return;
}

int main() {
	int t;
	cin >> t;
	// cout << "test: " << (10 % 1) << endl;
	while (t--) {
		string s;
		cin >> s >> mod;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < s.size(); ++i) ++cnt[s[i] - '0'];
		res = 0;
		dfs(s.size(), 0);
		cout << res << endl;
	}
	return 0;
}
