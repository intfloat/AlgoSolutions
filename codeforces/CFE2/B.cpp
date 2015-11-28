#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> A(n), B(m);
    FOR(i, n) scanf("%d", &A[i]);
    FOR(i, m) scanf("%d", &B[i]);
    sort(A.begin(), A.end());
    FOR(i, m) {
        int res = upper_bound(A.begin(), A.end(), B[i]) - A.begin();
        printf("%d ", res);
    }
    printf("\n");
    return 0;
}
