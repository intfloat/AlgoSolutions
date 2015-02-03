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
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

vector<int> dp;
int N, L, C;
vector<int> len;
vector<vector<int> > movies;

int solve(int status) {
    if (dp[status] >= 0) return dp[status];
    for (int i = 0; i < N; ++i) {
        if (status & (1 << i)) {
            int t = solve(status & (~(1 << i)));
            int pos = upper_bound(movies[i].begin(), movies[i].end(), t) - movies[i].begin();
            // all showtime are ok
            if (pos == movies[i].size()) --pos;
            // all showtime are too late
            else if (pos == 0) continue;
            else --pos;
            // if (movies[i][pos] + len[i] < t) continue;
            dp[status] = max(dp[status], len[i] + movies[i][pos]);
        }
    }
    dp[status] = max(dp[status], 0);
    return dp[status];
}

int main() {
    // freopen("movie.in", "r", stdin);
    // freopen("movie.out", "w", stdout);    
    scanf("%d %d", &N, &L);
    len.resize(N); movies.resize(N);
    dp.resize(1 << N);
    fill(dp.begin(), dp.end(), -1);
    dp[0] = 0;
    FOR(i, N) {
        scanf("%d %d", &len[i], &C);
        movies[i].resize(C);        
        FOR(j, C) scanf("%d", &movies[i][j]);
        sort(movies[i].begin(), movies[i].end());
        int ll = unique(movies[i].begin(), movies[i].end()) - movies[i].begin();
        movies[i].resize(ll);
    }
    int res = N + 10; 
    for (int i = 0; i < (1 << N); ++i) {
        int bits = __builtin_popcount(i);
        // can not be optimal solution
        if (bits >= res) continue;
        int dur = solve(i);
        // cout << i << " " << bits << " " << dur << endl;
        if (dur >= L) res = bits;
    }
    if (res > N) printf("-1\n");
    else printf("%d\n", res);
    return 0;
}
