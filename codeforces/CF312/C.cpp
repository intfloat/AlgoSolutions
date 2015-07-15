#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n, t;
    scanf("%d", &n);
    vector<int> arr(n);
    vector<vector<int> > ones(n, vector<int>());
    int mn = 30, val;
    FOR(i, n) {
        scanf("%d", &arr[i]);
        t = __builtin_popcount(arr[i]);
        if (t < mn) {
            mn = t;
            val = arr[i];
        }
        t = arr[i];
        for (int j = 20; j >= 0; --j) {
            if (t & (1 << j)) {
                ones[i].push_back(j);
            }
        }
    }
    int cur = 0, total = 0;
    int res = INT_MAX;
    int pv = -1;
    for (int i = 20; i >= 0; --i) {
        if ((1 << i) & val) {
            ++total;
            cur += (1 << i);
            int cnt = 0;
            vector<int> rem(20, 0);
            bool ok = true;
            FOR(j, n) {
                if (total > 1 && ones[j][total - 2] - ones[j][total - 1] != pv - i) {
                    ok = false;
                    break;
                }
                if (total == ones[j].size()) {
                    ++rem[ones[j][total - 1]];
                    continue;
                }
                else {
                    ++rem[ones[j][total - 1] - ones[j][total] - 1];
                    cnt += ones[j][total] + 1;
                }
            }
            if (!ok) break;
            vector<int> tmp(20, 0);
            FOR(j, 20) {
                FOR(k, 20) {
                    tmp[j] += rem[k] * abs(j - k);
                }
            }
            res = min(res, *min_element(tmp.begin(), tmp.end()) + cnt);
            pv = i;
        }
    }
    printf("%d\n", res);
    return 0;
}
