#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<pii> arr(n);
    FOR(i, n) scanf("%d %d", &arr[i].second, &arr[i].first);
    sort(arr.begin(), arr.end());
    int res = 0, ptr = 0, cur = 0;
    while (ptr < n) {
        if (arr[ptr].second >= cur) {
            ++res;
            cur = arr[ptr].first + 1;
        }
        ++ptr;
    }
    printf("%d\n", res);
    return 0;
}
