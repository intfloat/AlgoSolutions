#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    FOR(i, n) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    n = unique(arr.begin(), arr.end()) - arr.begin();
    arr.resize(n);
    vector<int> step(k * arr.back() + 1, -1);
    vector<int> q(k * arr.back() + 10);
    int p1 = 0, p2 = 0;
    step[k * arr[0]] = 0;
    q[p2++] = k * arr[0];
    while (p1 < p2) {
        int cur = q[p1++];
        FOR(i, n) {
            int val = cur + arr[i] - arr[0];
            if (step[val] < 0) {
                step[val] = step[cur] + 1;
                if (step[val] < k) {
                    q[p2++] = val;
                }
            }
        }
    }
    for (int i = k * arr[0]; i <= k * arr.back(); ++i) {
        if (step[i] >= 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
