#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
inline void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    deque<pii> dp;
    for (int i = 0; i < k; ++i) {
        pii cur = make_pair(arr[i], i);
        while (!dp.empty() && cur > dp.back()) dp.pop_back();
        dp.push_back(cur);
    }
    printf("%d ", dp.front().first);
    for (int i = k; i < n; ++i) {
        pii cur = make_pair(arr[i], i);
        while (!dp.empty() && cur > dp.back()) dp.pop_back();
        dp.push_back(cur);
        while (!dp.empty() && dp.front().second <= i - k) dp.pop_front();
        printf("%d ", dp.front().first);
    }
    printf("\n");
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
