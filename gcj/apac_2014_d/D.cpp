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

const int dir_x[] = {0, 0, -1, 1, 1, 1, -1, -1};
const int dir_y[] = {-1, 1, 0, 0, -1, 1, -1, 1};

const int nx[] = {2, 2, 1, -1, -2, -2, 1, -1};
const int ny[] = {1, -1, 2, 2, 1, -1, -2, -2};
bool check(int x, int y) {
	if (x < 0 || y < 0 || x >= 8 || y >= 8) return false;
	return true;
}
int main() {
	int T, N;
	char g[8][8];
	string s;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		cout << "Case #" << tt << ": ";
		cin >> N;
		FOR(i, 8) FOR(j, 8) g[i][j] = '.';
		FOR(i, N) {
			cin >> s;
			int r = s[0] - 'A', c = s[1] - '1';
			g[r][c] = s[3];
		}
		int res = 0;		
		FOR(i, 8) { FOR(j, 8) {
			// cout << "here" << endl;
			if (g[i][j] == '.') continue;
			if (g[i][j] == 'K') {
				FOR(k, 8) {
					int xx = i + dir_x[k], yy = j + dir_y[k];
					if (!check(xx, yy)) continue;
					if (g[xx][yy] != '.') ++res;
				}
			}
			if (g[i][j] == 'Q' || g[i][j] == 'R' || g[i][j] == 'B' || g[i][j] == 'P') {
				int begin = 0, end = 8, cnt = 9999;
				if (g[i][j] == 'R') end = 4;
				else if (g[i][j] == 'B') begin = 4;
				else if (g[i][j] == 'P') { begin = 4; end = 6; cnt = 1; }
				for (int k = begin; k < end; ++k) {
					int x = i, y = j;
					int tmp = cnt;
					while (cnt--) {						
						int xx = x + dir_x[k], yy = y + dir_y[k];
						x = xx; y = yy;
						// cout << "debug: " << xx << " " << yy << endl;
						if (!check(xx, yy)) break;
						if (g[xx][yy] != '.') { ++res; break; }
					}
					cnt = tmp;
				}
			}
			if (g[i][j] == 'N') {
				FOR(k, 8) {
					int xx = i + nx[k], yy = j + ny[k];
					if (!check(xx, yy)) continue;
					if (g[xx][yy] != '.') { ++res; }
				}
			}			
		} }
		cout << res << endl;
	}
	return 0;
}
