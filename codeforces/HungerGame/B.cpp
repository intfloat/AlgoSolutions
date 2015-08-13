#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int n, q, l, r, num;
    scanf("%d %d", &n, &q);
    vector<ll> arr(1, 0ll);
    FOR(i, n) {
        scanf("%d", &num);
        if (i % 2) arr.push_back(-num);
        else arr.push_back(num);
    }
    for (int i = 1; i <= n; ++i) {
        arr[i] += arr[i - 1];
    }
    FOR(i, q) {
        scanf("%d %d", &l, &r);
        if (l % 2) {
            printf("%I64d\n", arr[r] - arr[l - 1]);
        }
        else {
            printf("%I64d\n", arr[l - 1] - arr[r]);
        }
    }
    return 0;
}
