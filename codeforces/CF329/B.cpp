#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<double, int> pii;
int main() {
    int N, x1, x2;
    scanf("%d", &N);
    scanf("%d %d", &x1, &x2);
    vector<int> k(N), b(N);
    FOR(i, N) scanf("%d %d", &k[i], &b[i]);
    vector<pii> left, right;
    FOR(i, N) {
        left.push_back({k[i] * (x1 + 1e-9) + b[i], i});
        right.push_back({k[i] * (x2 - 1e-9) + b[i], i});
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    FOR(i, N) {
        if (left[i].second != right[i].second) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
