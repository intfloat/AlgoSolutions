#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int N;
    scanf("%d", &N);
    vector<bool> used(2 * N + 1, false);
    vector<int> elsie(N), bessie;
    FOR(i, N) {
        scanf("%d", &elsie[i]);
        used[elsie[i]] = true;
    }
    for (int i = 1; i <= 2 * N; ++i) {
        if (!used[i]) {
            bessie.push_back(i);
        }
    }
    sort(bessie.begin(), bessie.end(), greater<int>());
    sort(elsie.begin(), elsie.begin() + N / 2, greater<int>());
    int res = 0, ptr = 0;
    FOR(i, N / 2) {
        if (bessie[ptr] > elsie[i]) {
            ++ptr; ++res;
        }
    }
    sort(bessie.begin() + N / 2, bessie.end());
    sort(elsie.begin() + N / 2, elsie.end());
    ptr = N / 2;
    for (int i = N / 2; i < N; ++i) {
        if (bessie[ptr] < elsie[i]) {
            ++res; ++ptr;
        }
    }
    printf("%d\n", res);
    return 0;
}
