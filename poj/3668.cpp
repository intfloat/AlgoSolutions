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
    int N;
    vector<pair<int, int> > points;
    cin >> N;
    FOR(i, N) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }
    bool vertical = false;
    set<pair<int, int> > res;
    FOR(i, points.size()) {
        for (int j = i + 1; j < points.size(); ++j) {
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;
            if (dx == 0) vertical = true;
            else {
                int g = __gcd(abs(dx), abs(dy));
                dx /= g; dy /= g;
                if (dx < 0) { dx = -dx; dy = -dy; }
                res.insert(make_pair(dx, dy));
                // cout << dx << " " << dy << endl;
            }
        }
    }
    cout << res.size() + vertical << endl;
    return 0;
}
