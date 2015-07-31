#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 1000000;
int main() {
    int n, x;
    vector<int> arr(MAX_N + 1, 1);
    vector<bool> has(MAX_N + 1, false);
    scanf("%d", &n);
    FOR(i, n) {
        scanf("%d", &x);
        has[x] = true;
    }
    for (int i = 1; i <= MAX_N; ++i) {
        if (!has[i]) {
            continue;
        }
        int cur = arr[i] + 1;
        for (int j = i + i; j <= MAX_N; j += i) {
            if (has[j]) {
                arr[j] = max(arr[j], cur);
            }
        }
    }
    int res = *max_element(arr.begin(), arr.end());
    printf("%d\n", res);
    return 0;
}
