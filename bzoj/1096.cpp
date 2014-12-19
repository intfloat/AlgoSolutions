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

vector<ll> pos, num, cost, dp, sum, sump;
ll nume(int i, int j) {
    return dp[i] +  sump[i] - (dp[j] + sump[j]);
}

ll den(int i, int j) {
    return sum[i] - sum[j];
}

int main() {
    int N;
    cin >> N;
    pos.resize(N + 1); num.resize(N + 1); cost.resize(N + 1); dp.resize(N + 1);
    sum.resize(N + 1); sump.resize(N + 1);
    dp[0] = pos[0] = num[0] = cost[0] = sum[0] = sump[0] = 0;
    FOR(i, N) {
        cin >> pos[i + 1] >> num[i + 1] >> cost[i + 1];
        sum[i + 1] = sum[i] + num[i + 1];
        sump[i + 1] = sump[i] + num[i + 1] * pos[i + 1];
    }
    deque<int> q; q.push_back(0);
    for (int i = 1; i <= N; ++i) {
        while (q.size() >= 2 && nume(q[1], q[0]) < pos[i] * den(q[1], q[0])) q.pop_front();
        dp[i] = dp[q[0]] + (sum[i] - sum[q[0]]) * pos[i] - (sump[i] - sump[q[0]]) + cost[i];
        while (q.size() >= 2 && nume(i, q.back()) * den(q.back(), q[q.size() - 2]) <= nume(q.back(), q[q.size() - 2]) * den(i, q.back()))
            q.pop_back();
        q.push_back(i);
    }
    cout << dp[N] << endl;
    return 0;
}
