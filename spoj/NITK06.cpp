#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
inline void solve() {
    int N;
    scanf("%d", &N);
    arr.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = N - 1; i > 0; --i) {
        if (arr[i - 1] < arr[i]) {
            printf("NO\n");
            return;
        }
        arr[i - 1] -= arr[i];
        arr[i] = 0;
    }
    if (arr[0] == 0) {
        printf("YES\n");
    }
    else printf("NO\n");
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}
