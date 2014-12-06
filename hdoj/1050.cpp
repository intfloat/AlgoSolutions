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
    int T, N;
    cin >> T;
    vector<pair<int, int> > arr;
    while (T--) {
        cin >> N;
        arr.clear();
        FOR(i, N) {
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            arr.push_back(make_pair(x, y));
        }
        int mx = 0;
        FOR(i, 205) {
            int cnt = 0;
            FOR(j, arr.size()) {
                int low = (arr[j].first + 1) / 2;
                int up = (arr[j].second + 1) / 2;
                if (i >= low && i <= up) ++cnt;
            }
            mx = max(mx, cnt);
        }
        cout << mx * 10 << endl;
    }
    return 0;
}
