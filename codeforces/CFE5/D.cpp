#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    FOR(i, n) {
        scanf("%d", &arr[i]);
    }
    unordered_map<int, int> cnt;
    int mx = 0, l = 0, r = 0, ptr = 0, pv = 0;
    while (ptr < n) {
        ++cnt[arr[ptr]];
        if ((int)cnt.size() <= k) {
            if ((ptr - pv + 1) > mx) {
                mx = ptr - pv + 1;
                l = pv; r = ptr;
            }
        }
        else {
            while ((int)cnt.size() > k) {
                auto it = cnt.find(arr[pv]);
                --(it->second);
                if (it->second == 0) cnt.erase(it);
                ++pv;
            }
        }
        ++ptr;
    }
    printf("%d %d\n", l + 1, r + 1);
    return 0;
}
