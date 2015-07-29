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
class CheeseRolling {
public:
    vector<ll> waysToWin(vector <string>);
};

vector<ll> CheeseRolling::waysToWin(vector <string> wins) {
    int N = wins.size();
    vector<vector<bool> > ok(N, vector<bool>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ok[i][j] = (wins[i][j] == 'Y');
        }
    }
    vector<vector<int> > cnt(N + 1);
    for (int i = 0; i < (1 << N); ++i) {
        int c = __builtin_popcount(i);
        cnt[c].push_back(i);
    }
    vector<vector<ll> > dp(1 << N, vector<ll>(N, 0));
    for (int i = 0; i < N; ++i) {
        dp[1 << i][i] = 1;
    }
    for (int i = 0; i < (1 << N); ++i) {
        int c = __builtin_popcount(i);
        if (c != 2 && c != 4 && c != 8 && c != 16) {
            continue;
        }
        for (int p = 0; p < N; ++p) {
            if (!(i & (1 << p))) continue;
            for (int q = 0; q < N; ++q) {
                if (!ok[p][q] || p == q || !(i & (1 << q))) continue;
                int st = i - (1 << p) - (1 << q);
                int cc = c / 2 - 1;
                for (int j = 0; j < cnt[cc].size(); ++j) {
                    if ((cnt[cc][j] & st) != cnt[cc][j]) {
                        continue;
                    }
                    int t1 = st - cnt[cc][j] + (1 << p);
                    int t2 = cnt[cc][j] + (1 << q);
                    dp[i][p] += 2 * dp[t1][p] * dp[t2][q];
                }
            }
        }
    }
    return dp[(1 << N) - 1];
}

//Powered by [KawigiEdit] 2.0!
