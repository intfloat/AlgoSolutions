#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool vis[10];
void update(int num) {
    while (num > 0) {
        vis[num % 10] = true;
        num /= 10;
    }
}
inline void solve() {
    int N;
    cin >> N;
    memset(vis, false, sizeof vis);
    if (N == 0) {
        printf("INSOMNIA\n");
        return;
    }
    int val = N; update(val);
    while (accumulate(vis, vis + 10, 0) != 10) {
        val += N;
        update(val);
    }
    cout << val << endl;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
