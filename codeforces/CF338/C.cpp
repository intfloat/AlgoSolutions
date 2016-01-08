#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
string s, t, rs;
const int MAX_N = 3005;
short dp1[MAX_N][MAX_N], dp2[MAX_N][MAX_N];
int main() {
    memset(dp1, 0, sizeof dp1);
    memset(dp2, 0, sizeof dp2);
    cin >> s >> t;
    rs = s;
    reverse(rs.begin(), rs.end());
    int lens = s.size(), lent = t.size();
    for (int i = lens - 1; i >= 0; --i) {
        for (int j = lent - 1; j >= 0; --j) {
            if (s[i] == t[j]) dp1[i][j] = 1 + dp1[i + 1][j + 1];
            if (rs[i] == t[j]) dp2[i][j] = 1 + dp2[i + 1][j + 1];
        }
    }
    int res = 0, ptr = 0;
    vector<pii> step;
    while (ptr < lent) {
        int mx = 0, x1 = -1, x2 = -1;
        FOR(i, lens) {
            if (dp1[i][ptr] > mx) {
                mx = dp1[i][ptr];
                x1 = i; x2 = i + mx - 1;
            }
        }
        FOR(i, lens) {
            if (dp2[i][ptr] > mx) {
                mx = dp2[i][ptr];
                x1 = lens - 1 - i;
                x2 = lens - 1 - (i + mx - 1);
            }
        }
        if (mx == 0) {
            printf("-1\n");
            return 0;
        }
        else {
            ptr += mx;
            ++res;
            assert(x1 >= 0 && x2 >= 0);
            step.push_back({x1, x2});
        }
    }
    printf("%d\n", res);
    FOR(i, step.size()) {
        printf("%d %d\n", step[i].first + 1, step[i].second + 1);
    }
    return 0;
}
