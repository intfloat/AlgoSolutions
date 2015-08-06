#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int N;
    scanf("%d", &N);
    vector<pair<int, int> > arr(N);
    FOR(i, N) {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    vector<pair<int, int> > res(N);
    FOR(i, arr.size()) {
        int idx = arr[i].second;
        if (i == 0) {
            res[idx] = make_pair(arr[1].first - arr[0].first, arr.back().first - arr[0].first);
        }
        else if (i + 1 == arr.size()) {
            res[idx] = make_pair(arr[i].first - arr[i - 1].first, arr[i].first - arr[0].first);
        }
        else {
            int mn = min(arr[i].first - arr[i - 1].first, arr[i + 1].first - arr[i].first);
            int mx = max(arr[i].first - arr[0].first, arr.back().first - arr[i].first);
            res[idx] = make_pair(mn, mx);
        }
    }
    FOR(i, res.size()) {
        printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}
