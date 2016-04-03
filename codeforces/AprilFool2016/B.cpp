#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int tot = 720720;
vector<bool> work(tot + 1, false);
int main() {
    int N;
    cin >> N;
    vector<int> R(N), M(N);
    FOR(i, N) cin >> M[i];
    FOR(i, N) cin >> R[i];
    FOR(i, N) {
        for (int j = R[i]; j <= tot; j += M[i]) {
            work[j] = true;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= tot; ++i) {
        cnt += work[i];
    }
    cout << 1.0 * cnt / tot << endl;
    return 0;
}
