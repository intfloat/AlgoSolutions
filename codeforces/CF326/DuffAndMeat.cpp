#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), p(n);
    vector<pii> arr;
    FOR(i, n) {
        scanf("%d %d", &a[i], &p[i]);
        arr.push_back({p[i], i});
    }
    sort(arr.begin(), arr.end());
    int r = n - 1;
    int res = 0;
    FOR(i, arr.size()) {
        if (r < 0) break;
        if (arr[i].second > r) continue;
        for (int d = arr[i].second; d <= r; ++d) {
            res += a[d] * arr[i].first;
        }
        r = arr[i].second - 1;
    }
    printf("%d\n", res);
    return 0;
}
