#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
class ColorfulLineGraphsDiv2 {
public:
    int countWays(int, int);
};

int ColorfulLineGraphsDiv2::countWays(int N, int K) {
    vector<vector<ll> > dp(N, vector<ll>(K, 0));
    for (int i = 0; i < K; ++i) dp[0][i] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            // have no edge
            dp[i][j] = (dp[i - 1][0] * K) % MOD;
            for (int pv = 0; pv < i; ++pv) {
                dp[i][j] = (dp[i][j] + dp[i - 1][0] * (K - 1)) % MOD;
            }
        }
    }
    ll res = 0;
    for (int i = 0; i < K; ++i) {
        res = (res + dp[N - 1][i]) % MOD;
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
