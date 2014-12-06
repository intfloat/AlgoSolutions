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
    return p1.second < p2.second;
}

int main() {
    int N, x, y;
    while (cin >> N && N) {
        vector<pair<int, int> > arr;
        FOR(i, N) {
            cin >> x >> y;
            arr.push_back(make_pair(x, y));
        }
        sort(arr.begin(), arr.end(), cmp);
        int res = 1, prev = arr[0].second;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i].first >= prev) {
                ++res;
                prev = arr[i].second;
            }
        }
        cout << res << endl;
    }
}
