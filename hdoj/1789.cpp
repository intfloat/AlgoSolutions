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
    int T, ddl[1005], N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> v[1005];
        FOR(i, N) cin >> ddl[i];
        FOR(i, N) {
            int cost;
            cin >> cost;
            v[ddl[i]].push_back(cost);
        }
        int res = 0;
        vector<pair<int, int> > hp;
        int low = *min_element(ddl, ddl + N);
        int up = *max_element(ddl, ddl + N);
        for (int i = up; i >= 1; --i) {
            if (i < low && hp.size() == 0) break;
            FOR(j, v[i].size()) {
                hp.push_back(make_pair(v[i][j], i));
                push_heap(hp.begin(), hp.end());
            }
            // while (hp.size() > 0 && hp[0].second < i) {
            //     res += hp[0].first;
            //     pop_heap(hp.begin(), hp.end());
            //     hp.pop_back();
            // }
            if (hp.size() > 0) {
                pop_heap(hp.begin(), hp.end());
                hp.pop_back();
            }
        }
        FOR(i, hp.size()) res += hp[i].first;
        cout << res << endl;
    }
    return 0;
}
