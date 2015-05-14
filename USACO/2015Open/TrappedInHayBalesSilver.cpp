#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef pair<int, int> point;
typedef long long ll;
const int INF = static_cast<int>(1e9);
int main() {
    freopen("trapped.in", "r", stdin);
    freopen("trapped.out", "w", stdout);
    int N, pos;
    cin >> N >> pos;
    vector<point> arr(N);
    FOR(i, N) cin >> arr[i].second >> arr[i].first;
    sort(arr.begin(), arr.end());
    int mid = upper_bound(arr.begin(), arr.end(), make_pair(pos, 0)) - arr.begin();
    int res = INF;
    int ptr = mid;
    for (int i = mid - 1; i >= 0; --i) {
        while (ptr < arr.size() && arr[ptr].second <= arr[ptr].first - arr[i].first) ++ptr;
        if (ptr >= arr.size()) break;
        else res = min(res, max(0, arr[ptr].first - arr[i].first - arr[i].second));
    }
    ptr = mid - 1;
    for (int i = mid; i < arr.size(); ++i) {
        while (ptr >= 0 && arr[i].first - arr[ptr].first >= arr[ptr].second) --ptr;
        if (ptr < 0) break;
        else res = min(res, max(0, arr[i].first - arr[ptr].first - arr[i].second));
    }
    if (res == INF) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}
