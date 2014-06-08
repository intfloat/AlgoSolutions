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

const int SIZE = 10005;

int main() {
	int n, m;
	vector<int> g[SIZE];
	for(int i=0; i<SIZE; i++) g[i].clear();
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		g[x].push_back(y); g[y].push_back(x);
	}

	// maximum cardinality search algorithm 
	// to find perfect elimination ordering
	bool visited[SIZE];
	int c[SIZE];
	memset(visited, false, sizeof(visited));
	memset(c, 0, sizeof(c));
	vector<int> ord; ord.clear();
	c[0] = 1;
	for(int i=0; i<n; i++) {
		int mx = -1;
		int index = -1;
		for(int j=0; j<n; j++) {
			if(visited[j]==false && c[j]>mx) {
				mx = c[j];
				index = j;
			}
		}
		assert(mx >= 0);
		visited[index] = true;
		ord.push_back(index);
		for(vector<int>::iterator it=g[index].begin(); it!=g[index].end(); it++) {
			++c[*it];
		}
	} // end outer for loop

	// graph coloring, from n to 1
	int color[SIZE];
	memset(color, 0, sizeof(color));
	color[ord[0]] = 1;
	int res = 1;
	for(vector<int>::iterator it=ord.begin()+1; it!=ord.end(); it++) {
		set<int> s;
		s.clear();		
		int id = *it;
		int len = g[id].size();
		for(int i=0; i<len; i++) s.insert(color[g[id][i]]);
		// find smallest available color
		for(int i=1; ; i++) {
			if(s.find(i) == s.end()) {
				color[id] = i;
				res = max(res, i);
				break;
			}
		}
	}
	printf("%d\n", res);
	return 0;
}

