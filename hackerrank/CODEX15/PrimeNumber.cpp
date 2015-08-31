#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 1000000;
vector<bool> prime;
inline void preprocess() {
    prime.resize(MAX_N + 5);
    fill(prime.begin(), prime.end(), true);
    for (int i = 2; i * i <= MAX_N; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                prime[j] = false;
            }
        }
    }
}
int main() {
    preprocess();
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    vector<int> cnt(b + 5, 0);
    for (int i = 2; i <= b; ++i) {
        cnt[i] = cnt[i - 1] + prime[i];
    }
    if (cnt[b] - cnt[a - 1] < k) {
        printf("-1\n");
        return 0;
    }
    int res = -1;
    int ptr = a, val = 0;
    for (int i = a; i <= b; ++i) {
        if (cnt[b] - cnt[i - 1] < k) {
            res = max(res, b - i + 1 + 1);
            break;
        }
        while (cnt[ptr] - cnt[i - 1] < k) ++ptr;
        res = max(res, ptr - i + 1);
    }
    printf("%d\n", res);
    return 0;
}
