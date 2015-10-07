#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline bool isprime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
set<int> prime;
inline void preprocess() {
    for (int i = 2; i < 1000; ++i) {
        if (isprime(i)) prime.insert(i);
    }
}
int main() {
    preprocess();
    int n;
    scanf("%d", &n);
    set<int>::iterator it;
    if (prime.find(n) != prime.end()) {
        printf("1\n%d\n", n);
        return 0;
    }
    if (n < 1000) {
        for (it = prime.begin(); it != prime.end(); ++it) {
            int val = *it;
            if (prime.find(n - val) != prime.end()) {
                printf("2\n");
                printf("%d %d\n", val, n - val);
                return 0;
            }
        }
    }
    for (int i = n - 4; ; --i) {
        if (isprime(i)) {
            int rem = n - i;
            for (it = prime.begin(); it != prime.end(); ++it) {
                int val = *it;
                if (prime.find(rem - val) != prime.end()) {
                    printf("3\n");
                    printf("%d %d %d\n", i, val, rem - val);
                    return 0;
                }
            }
        }
    }
    return 0;
}
