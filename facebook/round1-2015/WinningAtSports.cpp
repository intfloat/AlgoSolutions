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

pair<int, int> get_score(const string& s) {
    int sc1 = 0, sc2 = 0;
    bool flag = false;
    FOR(i, s.size()) {
        if (s[i] == '-') {
            flag = true;
            continue;
        }
        if (!flag) sc1 = sc1 * 10 + (s[i] - '0');
        else sc2 = sc2 * 10 + (s[i] - '0');
    }
    return make_pair(sc1, sc2);
}

typedef long long ll;
const int MOD = 1000000007;
vector<ll> dp1[2005], dp2[2005];

void preprocess() {
    dp1[0].push_back(1); dp2[0].push_back(1);
    for (int i = 1; i < 2005; ++i) {
        dp1[i].resize(i); dp2[i].resize(i + 1);
        fill(dp1[i].begin(), dp1[i].end(), 0);
        fill(dp2[i].begin(), dp2[i].end(), 0);
        for (int j = 0; j < i; ++j) {
            if (j == 0) dp1[i][j] = dp2[i][j] = 1;
            else {
                if (i - j == 1) {
                    dp1[i][j] = dp1[i][j - 1];
                }
                else dp1[i][j] = (dp1[i - 1][j] + dp1[i][j - 1]) % MOD;
                assert(i > j);
                dp2[i][j] = (dp2[i - 1][j] + dp2[i][j - 1]) % MOD;
            }
        }
        dp2[i][i] = dp2[i][i - 1];
    }
    return;
}

int main() {
    int T;
    cin >> T;
    preprocess();
    FOR(tt, T) {
        string s;
        cin >> s;
        pair<int, int> score = get_score(s);
        assert(score.first > score.second);
        ll r1 = dp1[score.first][score.second];
        ll r2 = dp2[score.second][score.second];
        cout << "Case #" << tt + 1 << ": " << r1 << " " << r2 << endl;
    }
    return 0;
}
