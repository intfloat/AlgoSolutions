#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    FOR(i, n) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int res = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) continue;
        else {
            res += arr[i - 1] + 1 - arr[i];
            arr[i] = arr[i - 1] + 1;
        }
    }
    cout << res << endl;
    return 0;
}
