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

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return (1.0 * p1.first / p1.second) > (1.0 * p2.first / p2.second);
}

int main() {
    int n, m;
    vector<pair<int, int> > arr;
    while (cin >> m >> n) {
        if (n == -1 && m == -1) break;
        arr.clear();
        FOR(i, n) {
            int x, y;
            cin >> x >> y;
            arr.push_back(make_pair(x, y));
        }
        sort(arr.begin(), arr.end(), cmp);
        double res = 0;
        FOR(i, arr.size()) {
            if (m > arr[i].second) { res += arr[i].first; m -= arr[i].second; }
            else { res += m * (1.0 * arr[i].first / arr[i].second); m = 0; break; }
        }
        cout << fixed << setprecision(3) << res << endl;
    }
    return 0;
}
