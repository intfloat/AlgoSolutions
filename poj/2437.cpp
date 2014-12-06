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
    int N, L, x, y;
    cin >> N >> L;
    vector<pair<int, int> > arr;
    FOR(i, N) {
        cin >> x >> y;
        arr.push_back(make_pair(x, y));
    }
    sort(arr.begin(), arr.end());
    int res = 0, prev = -1;
    FOR(i, arr.size()) {
        // cout << i << " prev: " << prev << endl;
        int diff;
        if (prev < arr[i].first) diff = arr[i].second - arr[i].first;
        else if (prev >= arr[i].second - 1) continue;
        // the indexing scheme is weired
        else diff = arr[i].second - prev - 1;

        res += diff / L;
        if (diff % L != 0) {
            ++res;
            prev = arr[i].second + (L - diff % L) - 1;
        }
        else prev = arr[i].second - 1;
    }
    cout << res << endl;
    return 0;
}
