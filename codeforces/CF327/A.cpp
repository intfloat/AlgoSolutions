#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n + 2);
    FOR(i, n) scanf("%d", &arr[i + 1]);
    arr[0] = arr[1]; arr[n + 1] = arr[n];
    vector<pii> cnt;
    int ptr = 0;
    while (ptr < (int)arr.size()) {
        int l = ptr + 1;
        while (l < (int)arr.size() && arr[l] == arr[ptr]) ++l;
        if (l - 1 > ptr) cnt.push_back(make_pair(ptr, l - 1));
        ptr = l;
    }
    int res = 0;
    FOR(i, cnt.size()) {
        if (i + 1 == (int)cnt.size()) break;
        int l = cnt[i].second, r = cnt[i + 1].first;
        if (arr[l] == arr[r]) {
            res = max(res, (r - l - 1) / 2 + 1);
            for (int j = l + 1; j < r; ++j) arr[j] = arr[l];
        }
        else {
            int low = l + 1, up = r - 1, step = 0;
            while (low < up) {
                arr[low] = arr[l];
                arr[up] = arr[r];
                ++low; --up; ++step;
            }
            res = max(res, step);
        }
    }
    printf("%d\n", res);
    for (int i = 1; i <= n; ++i) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
