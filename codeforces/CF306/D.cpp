#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> point;
int main() {
    int k;
    cin >> k;
    if (k % 2 == 0) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    if (k == 1) {
        printf("2 1\n");
        printf("1 2\n");
        return 0;
    }
    vector<point> res;
    for (int i = 2; i <= k; ++i) res.push_back(make_pair(1, i));
    for (int i = 2; i <= k; ++i) {
        for (int j = i + 1; j <= k; ++j) {
            if (i % 2 == 0 && j == i + 1) continue;
            res.push_back(make_pair(i, j));
        }
    }
    for (int i = 2; i <= k; ++i) {
        res.push_back(make_pair(i, k + 1));
        res.push_back(make_pair(i, k + 2));
    }
    res.push_back(make_pair(k + 1, k + 2));
    int sz = res.size();
    FOR(i, sz) res.push_back(make_pair(res[i].first + k + 2, res[i].second + k + 2));
    res.push_back(make_pair(1, k + 3));
    printf("%d %d\n", 2 * (k + 2), res.size());
    FOR(i, res.size()) {
        printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}
