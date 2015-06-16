#include <stdio.h>
#include <vector>
#include <limits.h>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> point;
inline void solve() {
    int N, M, mx, x, y;
    scanf("%d", &N);
    vector<point> arr(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &M);
        mx = INT_MIN;
        for (int j = 0; j < M; ++j) {
            scanf("%d %d", &x, &y);
            mx = max(mx, x);
        }
        arr[i] = make_pair(mx, i);
    }
    sort(arr.begin(), arr.end());
    vector<int> res(N);
    for (int i = 0; i < N; ++i) {
        res[arr[i].second] = i;
    }
    for (int i = 0; i < N; ++i) {
        printf("%d ", res[i]);
    }
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
