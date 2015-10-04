#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n * n);
    map<int, int> cnt;
    FOR(i, n * n) {
        scanf("%d", &arr[i]);
        ++cnt[arr[i]];
    }
    sort(arr.begin(), arr.end(), greater<int>());
    vector<int> res;
    FOR(i, n * n) {
        if (cnt[arr[i]] > 0) {
            FOR(j, res.size()) {
                int g = __gcd(res[j], arr[i]);
                if (cnt[g] > 0) cnt[g] -= 2;
            }
            res.push_back(arr[i]);
            --cnt[arr[i]];
        }
        if ((int)res.size() == n) break;
    }
    FOR(i, n) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
