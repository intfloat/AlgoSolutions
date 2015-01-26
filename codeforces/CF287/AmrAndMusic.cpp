#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    int n, k, t;
    vector<pair<int, int> > days;
    scanf("%d %d", &n, &k);
    FOR(i, n) {
        scanf("%d", &t);
        days.emplace_back(make_pair(t, i));
    }
    sort(days.begin(), days.end());
    int cur = 0;
    vector<int> res;
    FOR(i, days.size()) {
        if (cur + days[i].first > k) break;
        else {
            cur += days[i].first;
            res.emplace_back(days[i].second + 1);
        }
    }
    printf("%d\n", res.size());
    FOR(i, res.size()) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
