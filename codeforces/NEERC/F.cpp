#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool visited[10005];
vector<pii> arr;
int n;
inline bool check(int mid) {
    memset(visited, false, sizeof visited);
    FOR(i, n) {
        int rem = mid;
        for (int j = arr[i].second; j < arr[i].first; ++j) {
            if (rem == 0) break;
            if (!visited[j]) {
                visited[j] = true;
                --rem;
            }
        }
        if (rem > 0) return false;
    }
    return true;
}
int main() {
    scanf("%d", &n);
    arr.resize(n);
    int l = 0, r = 10000;
    FOR(i, n) {
        scanf("%d %d", &arr[i].second, &arr[i].first);
        r = min(r, arr[i].first - arr[i].second);
    }
    sort(arr.begin(), arr.end());
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    if (l + 1 == r && check(r)) printf("%d\n", r * n);
    else printf("%d\n", l * n);
    return 0;
}
