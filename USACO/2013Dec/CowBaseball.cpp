#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
int main() {
    freopen("baseball.in", "r", stdin);
    freopen("baseball.out", "w", stdout);
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    FOR(i, n) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int d = arr[j] - arr[i];
            res += upper_bound(arr.begin(), arr.end(), arr[j] + 2 * d)
                    - lower_bound(arr.begin(), arr.end(), arr[j] + d);
        }
    }
    printf("%d\n", res);
    return 0;
}
