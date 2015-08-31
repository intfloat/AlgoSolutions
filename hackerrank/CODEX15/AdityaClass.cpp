#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
int main() {
    int n;
    scanf("%d", &n);
    vector<point> arr(n);
    FOR(i, n) {
        scanf("%d %d", &arr[i].second, &arr[i].first);
    }
    sort(arr.begin(), arr.end());
    int res = 0, cur = 0;
    FOR(i, n) {
        if (cur <= arr[i].second) {
            cur = arr[i].first;
            ++res;
        }
    }
    printf("%d\n", res);
    return 0;
}
