#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int N;
    scanf("%d", &N);
    vector<bool> visited(2 * N + 1, false);
    vector<int> elsie(N), bessie;
    FOR(i, N) {
        scanf("%d", &elsie[i]);
        visited[elsie[i]] = true;
    }
    for (int i = 1; i <= 2 * N; ++i) {
        if (!visited[i]) bessie.push_back(i);
    }
    sort(elsie.begin(), elsie.end(), greater<int>());
    sort(bessie.begin(), bessie.end(), greater<int>());
    int ptr = 0, res = 0;
    FOR(i, N) {
        if (elsie[i] > bessie[ptr]) bessie.pop_back();
        else {
            ++ptr;
            ++res;
        }
    }
    printf("%d\n", res);
    return 0;
}
