#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n), res;
    FOR(i, n) {
        scanf("%d", &arr[i]);
    }
    res.push_back(arr[0]);
    for (int i = 1; i < n; ++i) {
        if (__gcd(arr[i], arr[i - 1]) > 1) {
            res.push_back(1);
        }
        res.push_back(arr[i]);
    }
    printf("%d\n", (int)res.size() - n);
    FOR(i, res.size()) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
