#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<pii> arr;
    vector<int> x(n);
    FOR(i, n) {
        scanf("%d", &x[i]);
        arr.push_back({x[i], i});
    }
    sort(arr.begin(), arr.end());
    map<pii, int> mp;
    FOR(i, n) {
        mp[arr[i]] = i;
    }
    int res = 0, mx = -1;
    FOR(i, n) {
        mx = max(mx, mp[{x[i], i}]);
        if (mx == i) ++res;
    }
    printf("%d\n", res);
    return 0;
}
