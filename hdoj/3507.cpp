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

typedef long long ll;

vector<ll> sum;
vector<ll> dp;
ll num(int i, int j) {
    return dp[i] + sum[i] * sum[i] - (dp[j] + sum[j] * sum[j]);
}

ll den(int i, int j) {
    return 2 * (sum[i] - sum[j]);
}

int main() {
    int N, M;
    ll t;
    while (scanf("%d %d", &N, &M) != EOF) {
        dp.resize(N + 1); sum.resize(N + 1);
        dp[0] = sum[0] = 0;
        FOR(i, N) { scanf("%lld", &t); sum[i + 1] = sum[i] + t; }
        deque<int> q; q.push_back(0);
        for (int i = 1; i <= N; ++i) {
            while (q.size() >= 2 && num(q[1], q[0]) < sum[i] * den(q[1], q[0])) q.pop_front();
            dp[i] = dp[q[0]] + (sum[i] - sum[q[0]]) * (sum[i] - sum[q[0]]) + M;
            // It turns out that equal sign does matter... makes perfect sense, a better solution is followed by falt area
            while (q.size() >= 2 && num(i, q.back()) * den(q.back(), q[q.size() - 2]) <= num(q.back(), q[q.size() - 2]) * den(i, q.back()))
                q.pop_back();
            q.push_back(i);
        }
        printf("%lld\n", dp[N]);
    }
    return 0;
}
