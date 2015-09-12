#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
inline void solve() {
    int N;
    scanf("%d", &N);
    vector<int> to(N);
    vector<bool> visited(N, false);
    int cycle = 0;
    FOR(i, N) {
        scanf("%d", &to[i]);
        --to[i];
    }
    FOR(i, N) {
        if (!visited[i]) {
            int ptr = i;
            ++cycle;
            while (!visited[ptr]) {
                visited[ptr] = true;
                ptr = to[ptr];
            }
        }
    }
    printf("%d\n", cycle - 1);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
