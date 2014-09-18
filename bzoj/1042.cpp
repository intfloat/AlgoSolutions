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

using namespace std;

int main() {
    int c[4], total, cnt[4];
    int dp[4][100005];
    for (int i = 0; i < 4; ++i) scanf("%d", c + i);
    scanf("%d", &total);
    while (total--) {
        int s;
        for (int i = 0; i < 4; ++i) scanf("%d", cnt + i);
        scanf("%d", &s);
        memset(dp, 0, sizeof(dp));
        // first currency
        for (int i = 0; i <= cnt[0]; ++i) {
            if (i * c[0] > s) break;
            dp[0][i * c[0]] = 1;
        }
        // remaining currency
        for (int i = 1; i < 4; ++i) {
            for (int j = 0; j <= cnt[i]; ++j) {
                for (int t = j * c[i]; t <= s; ++t) {
                    dp[i][t] += dp[i - 1][t - j * c[i]];
                }
            }
        }
        printf("%d\n", dp[3][s]);
    }
    return 0;
}
