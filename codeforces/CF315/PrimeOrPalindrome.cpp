#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 3000000;
vector<bool> prime(MAX_N + 1, true), palin(MAX_N + 1, false);
inline void preprocess() {
    prime[0] = prime[1] = false;
    for (int i = 2; i <= MAX_N; ++i) {
        if (prime[i]) {
            for (int j = i + i; j <= MAX_N; j += i) {
                prime[j] = false;
            }
        }
    }
    palin[0] = false;
    for (int i = 1; i < 10; ++i) {
        palin[i * 10 + i] = true;
        palin[i] = true;
    }
    int cur = 100;
    for (int i = 100; i <= MAX_N; ++i) {
        if (cur * 10 <= i) {
            cur *= 10;
            // assert(cur * 10 > i);
        }
        palin[i] = true;
        int p1 = cur, p2 = 1;
        while (p1 > p2) {
            int r1 = (i / p1) % 10;
            int r2 = (i / p2) % 10;
            if (r1 != r2) {
                palin[i] = false;
                break;
            }
            p1 /= 10; p2 *= 10;
        }
    }
    return;
}
int main() {
    int p, q;
    preprocess();
    scanf("%d %d", &p, &q);
    int g = __gcd(p, q);
    p /= g; q /= g;
    ll cnt1 = 0, cnt2 = 0;
    int res = 0;
    vector<int> arr;
    for (int i = 1; i <= MAX_N; ++i) {
        cnt1 += prime[i];
        cnt2 += palin[i];
        if (cnt1 * q > cnt2 * p) {
            if (arr.empty() || arr.back() != i - 2) {
                res = i - 1;
            }
            arr.push_back(i - 1);
        }
    }
    printf("%d\n", res);
    return 0;
}
