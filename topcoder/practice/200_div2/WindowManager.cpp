#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

using namespace std;

class WindowManager {
public:
	vector <string> screen(int, int, vector <string>);
};

vector <string> WindowManager::screen(int height, int width, vector <string> windows) {
	vector<string> res;
	string row = "";
	for (int i = 0; i < width; ++i) row += ' ';
	for (int i = 0; i < height; ++i) res.push_back(row);
	int len = windows.size();
	stringstream ss;
	ss.clear();
	int v1, h1, vs, hs;
	char c;
	for (int i = 0; i < len; ++i) {
		ss.clear();
		ss << windows[i];
		ss >> v1 >> h1 >> vs >> hs >> c;
		int v2 = v1 + vs - 1;
		int h2 = h1 + hs - 1;
		if (v1 >= 0 && v1 < height) {
			if (h1 >= 0 && h1 < width) {
				res[v1][h1] = '+';
				for (int j = v1+1; j < min(height, v2); ++j) res[j][h1] = '|';
			}
			if (h2 >= 0 && h2 < width) {
				res[v1][h2] = '+';
				for (int j = v1+1; j < min(height, v2); ++j) res[j][h2] = '|';
			}
			int left = max(h1+1, 0);
			int right = min(width-1, h2-1);
			for (int j = left; j <= right; ++j) res[v1][j] = '-';
		}
		if (v2 >= 0 && v2 < height) {
			if (h1 >= 0 && h1 < width) {
				res[v2][h1] = '+';
				for (int j = v2-1; j >= max(0, v1+1); --j) res[j][h1] = '|';
			}
			if (h2 >= 0 && h2 < width) {
				res[v2][h2] = '+';
				for (int j = v2-1; j >= max(0, v1+1); --j) res[j][h2] = '|';
			}
			int left = max(0, h1 + 1);
			int right = min(width-1, h2 - 1);
			for (int j = left; j <= right; ++j) res[v2][j] = '-';
		}
		if (h1 >= 0 && h1 < width) {
			int up = max(0, v1+1);
			int down = min(height-1, v2-1);
			for (int j = up; j <= down; ++j) res[j][h1] = '|';
		}
		if (h2 >= 0 && h2 < width) {
			int up = max(0, v1+1);
			int down = min(height-1, v2-1);
			for (int j = up; j <= down; ++j) res[j][h2] = '|';
		}
		int x1 = max(0, v1 + 1);
		int y1 = max(0, h1 + 1);
		int x2 = min(height - 1, v2 - 1);
		int y2 = min(width - 1, h2 - 1);
		for (int j = x1; j <= x2; ++j)
		for (int k = y1; k <= y2; ++k)
			res[j][k] = c;
	}
	return res;
}


//Powered by [KawigiEdit] 2.0!