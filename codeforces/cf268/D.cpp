// type the wrong variable name... bei zi ji zha ku le ><
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

const int MAX_N = 100005;
int main(){
	int n, a, b, arr[MAX_N];
	map<int, int> m;
	map<int, int> res;
	bool visited[MAX_N];
	memset(visited, false, sizeof(visited));	
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; ++i) {
	    scanf("%d", arr + i);
	    m[arr[i]] = i;
	}
	bool ok = true;
	set<int> s;
	for (int i = 0; i < n; ++i) {
		if (!ok) break;
		if (res.find(arr[i]) != res.end()) continue;
		// try A
		s.clear();
		queue<int> q;
		vector<int> tmp;
		q.push(arr[i]); s.insert(arr[i]);		
		while (!q.empty()) {
			int tp = q.front(); q.pop();
			res[tp] = 0;
			tmp.push_back(tp);
			// cout << "0: " << tp << endl;
			// if (tp == 69962)
			if (m.find(a - tp) == m.end()) {
				ok = false;
				break;
			}
			if (s.find(a - tp) == s.end()) {
				// if (tp == 69962) cout << "tag:" << a - tp << endl;
				s.insert(a - tp);
				q.push(a - tp);
			}
			if (m.find(b - tp) != m.end() && s.find(b - tp) == s.end()) {
				// cout << "0: " << (b - arr[i]) << endl;
				s.insert(b - tp);
				q.push(b - tp);
			}
		}
		if (ok) continue;
		for (int j = 0; j < tmp.size(); ++j) {
			res.erase(res.find(tmp[j]));
		}
		// try B
		ok = true;
		s.clear();
		while (!q.empty()) q.pop();
		q.push(arr[i]); s.insert(arr[i]);		
		while (!q.empty()) {
			int tp = q.front(); q.pop();
			res[tp] = 1;
			// cout << "1: " << tp << endl;
			if (m.find(b - tp) == m.end()) {
				ok = false;
				break;
			}
			if (s.find(b - tp) == s.end()) {
				s.insert(b - tp);
				q.push(b - tp);
			}
			if (m.find(a - tp) != m.end() && s.find(a - tp) == s.end()) {
				// cout << "1: " << (a - arr[i]) << endl;
				s.insert(a - tp);
				q.push(a - tp);
			}
		}
	}

	if (!ok) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; ++i) cout << res[arr[i]] << " ";
		cout << endl;
	}
	return 0;
}
