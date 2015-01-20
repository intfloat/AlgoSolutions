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

const int MAX_N = 30005;
int dp[MAX_N][3];

int main() {
    int N, arr[MAX_N];
    cin >> N;
    FOR(i, N) { cin >> arr[i]; --arr[i]; }
    FOR(i, 3) dp[0][i] = 1;
    dp[0][arr[0]] = 0;

    for (int i = 1; i < N; ++i) {
        dp[i][0] = dp[i - 1][0] + (arr[i] != 0);
        dp[i][1] = min(dp[i - 1][1] + (arr[i] != 1), dp[i - 1][0] + (arr[i] != 1));
        dp[i][2] = min(dp[i - 1][2] + (arr[i] != 2), dp[i - 1][1] + (arr[i] != 2));
        dp[i][2] = min(dp[i][2], dp[i - 1][0] + (arr[i] != 2));
    }
    int res = *min_element(dp[N - 1], dp[N - 1] + 3);

    FOR(i, 3) dp[0][i] = 1;
    dp[0][arr[0]] = 0;

    for (int i = 1; i < N; ++i) {
        dp[i][0] = min(dp[i - 1][0] + (arr[i] != 0), dp[i - 1][1] + (arr[i] != 0));
        dp[i][0] = min(dp[i][0], dp[i - 1][2] + (arr[i] != 0));
        dp[i][1] = min(dp[i - 1][1] + (arr[i] != 1), dp[i - 1][2] + (arr[i] != 1));
        dp[i][2] = dp[i - 1][2] + (arr[i] != 2);        
    }

    res = min(res, *min_element(dp[N - 1], dp[N - 1] + 3));
    cout << res << endl;
    return 0;
}
