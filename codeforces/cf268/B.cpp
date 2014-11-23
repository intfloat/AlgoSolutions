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

int main(){
	int p, q, l, r, x, y;
	cin >> p >> q >> l >> r;
	set<int> s;
	for (int i = 0; i < p; ++i) {
		cin >> x >> y;
		for (int j = x; j <= y; ++j) s.insert(j);
	}
	vector<int> v;
	for (int i = 0; i < q; ++i) {
		cin >> x >> y;
		for (int j = x; j <= y; ++j) v.push_back(j);
	}
	int res = 0;
	int len = v.size();
	for (int i = l; i <= r; ++i) {
		bool ok = false;
		for (int j = 0; j < len; ++j) {
			if (s.find(v[j] + i) != s.end()) {
				ok = true;
				break;
			}
		}
		res += (ok == true);
	}
	cout << res << endl;
	return 0;
}
