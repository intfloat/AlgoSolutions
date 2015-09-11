#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int N;
    scanf("%d", &N);
    vector<int> primes;
    for (int i = 2; i <= N; ++i) {
        bool ok = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                ok = false;
                break;
            }
        }
        if (ok) primes.push_back(i);
    }
    vector<int> res;
    FOR(i, primes.size()) {
        int val = primes[i];
        while (val <= N) {
            res.push_back(val);
            val *= primes[i];
        }
    }
    printf("%d\n", res.size());
    FOR(i, res.size()) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
