#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    FOR(i, n) scanf("%d", &arr[i]);
    ll res = abs(arr[0]);
    for (int i = 1; i < n; ++i) {
        res += abs(arr[i] - arr[i - 1]);
    }
    cout << res << endl;
    return 0;
}
