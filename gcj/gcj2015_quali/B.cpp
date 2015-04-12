#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    int N, D;
    vector<int> numbers;
    cin >> N;
    FOR(tt, N) {
        cin >> D;
        numbers.resize(D);
        FOR(i, D) cin >> numbers[i];        
        int res = 1005, mx = *max_element(numbers.begin(), numbers.end());
        // enumerate maximum number
        for (int i = 1; i <= mx; ++i) {
            int cur = 0;
            FOR(j, numbers.size()) {
                if (numbers[j] % i == 0) cur += numbers[j] / i - 1;
                else cur += numbers[j] / i;
            }
            res = min(res, cur + i);
        }
        cout << "Case #" << tt + 1 << ": " << res << endl;
    }
    return 0;
}
