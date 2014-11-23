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

#define MP(x, y) make_pair(x, y)

using namespace std;

typedef pair<int, int> PII;
const int MAX_N = 100005;

int main() {
	int n;
	scanf("%d", &n);
	vector<PII> res;
	bool visited[MAX_N];
	bool prime[MAX_N];
	memset(visited, false, sizeof(visited));
	memset(prime, true, sizeof(prime));
	for(int i=2; i<=n; ++i) {
		if (!prime[i]) continue;
		for(int j=2*i; j<=n; j+=i) prime[j] = false;
	} 
	vector<int> v;
	for(int i=3; i<=n; i++) {
		if (!prime[i]) continue;
		v.clear();
		for(int j=i; j<=n; j+=i) {
			if (!visited[j]) v.push_back(j);
		}
		int len = v.size();
		if (len == 1) continue;
		if (len&1) {v.erase(v.begin()+1); --len; }
		for(int j=0; j<len; j+=2) {
			visited[v[j]] = true;
			visited[v[j+1]] = true;
			res.push_back(MP(v[j], v[j+1]));
		}
	}
	v.clear();
	for (int i=2; i<=n; i+=2) {
		if (!visited[i]) v.push_back(i);
	}
	int len = v.size();
	if (len&1) {v.erase(v.begin()); --len; }
	for (int i=0; i<len; i+=2) {
		res.push_back(MP(v[i], v[i+1]));
	}

	// output result
	printf("%d\n", res.size());
	for (vector<PII>::iterator it=res.begin(); it!=res.end(); ++it) {
		printf("%d %d\n", (*it).first, (*it).second);
	}
	return 0;
}
