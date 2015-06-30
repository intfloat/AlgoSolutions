#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> point;
int main() {
    int n;
    scanf("%d", &n);
    vector<point> arr(n);
    vector<int> cnt(201, 0);
    FOR(i, n) scanf("%d", &arr[i].first);
    int total = 0;
    FOR(i, n) {
        scanf("%d", &arr[i].second);
        total += arr[i].second;
        ++cnt[arr[i].second];
    }
    sort(arr.begin(), arr.end(), greater<point>());
    int res = INT_MAX, ptr = 0;
    while (ptr < n) {
        int i;
        for (i = ptr + 1; i < n; ++i) {
            if (arr[i].first != arr[ptr].first) {
                break;
            }
        }
        int cost = 0;
        for (int j = ptr; j < i; ++j) {
            cost += arr[j].second;
            --cnt[arr[j].second];
        }
        int rem = max(0, i - ptr - 1);
        for (int j = 200; j > 0; --j) {
            if (rem > cnt[j]) {
                rem -= cnt[j];
                cost += cnt[j] * j;
            }
            else {
                cost += rem * j;
                rem = 0;
                break;
            }
        }
        res = min(res, total - cost);
        ptr = i;
    }
    printf("%d\n", res);
    return 0;
}
