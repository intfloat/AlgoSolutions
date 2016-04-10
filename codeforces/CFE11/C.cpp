#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    vector<int> ones;
    FOR(i, n) {
        scanf("%d", &arr[i]);
        arr[i] = 1 - arr[i];
        if (arr[i]) ones.push_back(i);
    }
    int sz = ones.size(), res = -1;
    int l = -1, r = -1;
    FOR(i, n) {
        int pos = lower_bound(ones.begin(), ones.end(), i) - ones.begin();
        int p2 = min(sz, pos + k);
        if (p2 == sz) p2 = n;
        else p2 = ones[p2];
        pos = i;
        int cur = p2 - pos;
        if (cur > res) {
            res = cur;
            l = pos; r = p2;
        }
    }
    printf("%d\n", res);
    for (int i = l; i < r; ++i) arr[i] = 0;
    FOR(i, n) {
        printf("%d ", 1 - arr[i]);
    }
    printf("\n");
    return 0;
}
