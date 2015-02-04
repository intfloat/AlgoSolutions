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
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#include <tuple>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    freopen("stampede.in", "r", stdin);
    freopen("stampede.out", "w", stdout);
    int N, x, y, r;
    vector<tuple<int, int, int> > events;
    scanf("%d", &N);
    FOR(i, N) {
        scanf("%d %d %d", &x, &y, &r);
        // entering event
        events.emplace_back(make_tuple(-r * (x + 1), x, y));
        // leaving event
        events.emplace_back(make_tuple(-r * x, x, -y));
    }
    sort(events.begin(), events.end());
    set<int> res, ys;
    int i = 0;
    while (i < events.size()) {
        int tm = get<0>(events[i]);
        while (i < events.size() && get<0>(events[i]) == tm) {
            int ny = get<2>(events[i]);
            if (ny > 0) ys.insert(ny);
            else ys.erase(-ny);
            ++i;
        }
        if (!ys.empty()) res.insert(*ys.begin());
    }    
    assert(ys.size() == 0);
    printf("%d\n", static_cast<int>(res.size()));
    return 0;
}
