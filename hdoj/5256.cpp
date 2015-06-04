#include <stdio.h>
#include <vector>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
const int MAX_N = 100005;
int arr[MAX_N];
void solve() {
    int n, pos;
    scanf("%d", &n);
    FOR(i, n) scanf("%d", arr + i);
    FOR(i, n) arr[i] += n - 1 - i;
    vector<int> v;
    FOR(i, n) {
        pos = upper_bound(v.begin(), v.end(), arr[i]) - v.begin();
        if (pos == v.size()) v.push_back(arr[i]);
        else v[pos] = arr[i];
    }
    printf("%d\n", n - v.size());
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
