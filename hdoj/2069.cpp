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

const int val[] = {1, 5, 10, 25, 50};
int dp[5][255][105];
int main() {
    int N;
    while (cin >> N) {
        memset(dp, 0, sizeof(dp));
        FOR(i, min(N, 100) + 1) dp[0][i][i] = 1;
        for (int i = 1; i < 5; ++i) {
            for (int v = 0; v <= N; ++v) {
                for (int c = 0; c <= 100; ++c) {
                    for (int cur = 0; cur <= c; ++cur) {
                        if (cur * val[i] > v) break;
                        dp[i][v][c] += dp[i - 1][v - cur * val[i]][c - cur];
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= 100; ++i) res += dp[4][N][i];
        cout << res << endl;
    }
    return 0;
}
