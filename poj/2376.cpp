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
using namespace std;

int main() {
    int n, t;
    pair<int, int> interval[25005];
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i) scanf("%d%d", &interval[i].first, &interval[i].second);
    sort(interval, interval + n);
    int res = 0;
    int cur = 1;
    int ptr = 0;
    // greedy selection
    while (cur <= t) {
        int mx = -1;
        while (ptr < n && interval[ptr].first <= cur) {
            if (interval[ptr].second >= cur)
                mx = max(mx, interval[ptr].second);
            ++ptr;
        }
        if (mx < 0) {
            printf("-1\n");
            return 0;
        }
        cur = mx + 1;
        ++res;
    }
    printf("%d\n", res);
    return 0;
}
