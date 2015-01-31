#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

vector<bool> primes;
vector<short int> cnt;

void precompute() {
    int cap = int(1e7) + 5;
    primes.resize(cap); cnt.resize(cap);
    fill(primes.begin(), primes.end(), true);
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = 2; i < cap; ++i) {
        if (!primes[i]) continue;
        int cur = i;
        while (cur < cap) {
            ++cnt[cur]; primes[cur] = false; cur += i;
        }
    }
    return;
}

int main() {
    int T;
    cin >> T;
    // clock_t start = clock();
    precompute();
    // cout << "total time: " << clock() - start << endl;
    FOR(i, T) {
        int a, b, k;
        cin >> a >> b >> k;
        int res = 0;
        if (k < 9) for (int j = a; j <= b; ++j) res += (cnt[j] == k);
        cout << "Case #" << i + 1 << ": " << res << endl;
    }
    return 0;
}
