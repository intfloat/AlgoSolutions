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
    int C, n, m, dp[105];
    cin >> C;
    while (C--) {
        cin >> n >> m;
        memset(dp, 0, sizeof(dp));
        FOR(i, m) {
            int p, h, c;
            cin >> p >> h >> c;
            for (int j = n; j >= p; --j)
                for (int cnt = 1; cnt <= c; ++cnt)
                    if (j - cnt * p >= 0) dp[j] = max(dp[j], dp[j - cnt * p] + cnt * h);
        }
        cout << *max_element(dp, dp + n + 1) << endl;
    }
    return 0;
}
