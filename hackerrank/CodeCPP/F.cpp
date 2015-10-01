#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int MAX_N = 10000000;
vector<int> primes;
inline void preprocess() {
    vector<bool> ok(5000, true);
    for (int i = 2; i * i <= MAX_N; ++i) {
        if (ok[i]) {
            primes.push_back(i);
            for (int j = i + i; j < 5000; j += i) {
                ok[j] = false;
            }
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    preprocess();
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    map<int, int> mp;
    vector<int> res(n);
    for (int i = n - 1; i >= 0; --i) {
        int cur = n;
        for (int j = 0; primes[j] * primes[j] <= arr[i] && j < primes.size(); ++j) {
            if (arr[i] % primes[j] == 0) {
                if (mp.find(primes[j]) != mp.end()) {
                    cur = min(cur, mp[primes[j]]);
                }
                mp[primes[j]] = i;
                while (arr[i] % primes[j] == 0) arr[i] /= primes[j];
            }
        }
        if (arr[i] > 1) {
            if (mp.find(arr[i]) != mp.end()) {
                cur = min(cur, mp[arr[i]]);
            }
            mp[arr[i]] = i;
        }
        if (cur == n) res[i] = -1;
        else res[i] = cur + 1;
    }
    for (int i = 0; i < n; ++i) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
