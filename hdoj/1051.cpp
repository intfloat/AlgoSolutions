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
    vector<pair<int, int> > arr;
    int T, n;
    bool visited[5005];
    cin >> T;
    while (T--) {
        arr.clear();
        memset(visited, false, sizeof(visited));
        cin >> n;
        FOR(i, n) {
            int x, y;
            cin >> x >> y;
            arr.push_back(make_pair(x, y));
        }
        sort(arr.begin(), arr.end());
        int res = 0;
        FOR(i, arr.size()) {
            if (!visited[i]) {
                ++res; visited[i] = true;
                int prev = i;
                for (int j = i + 1; j < n; ++j) {
                    if (!visited[j]
                        && arr[j].first >= arr[prev].first
                        && arr[j].second >= arr[prev].second) {
                        prev = j;
                        visited[j] = true;
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}

