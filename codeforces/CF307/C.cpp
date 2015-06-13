#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
vector<int> arr, tp;
int n, stud;
bool check(ll mid) {
    tp = arr;
    int rem = stud;
    for (int i = n - 1; i >= 0; --i) {
        if (tp[i] == 0) continue;
        if (mid <= i + 1) return false;
        ll avg = mid - (i + 1);
        ll cnt = tp[i] / avg;
        if (tp[i] % avg) {
            ++cnt;
            ll cc = avg - tp[i] % avg;
            for (int j = i - 1; j >= 0; --j) {
                if (tp[j] < cc) {
                    cc -= tp[j];
                    tp[j] = 0;
                }
                else {
                    tp[j] -= cc;
                    cc = 0;
                    break;
                }
            }
        }
        rem -= cnt;
        if (rem < 0) return false;
    }
    return true;
}
int main() {
    scanf("%d %d", &n, &stud);
    arr.resize(n);
    FOR(i, n) scanf("%d", &arr[i]);
    ll left = 0, right = (ll)(1e15 + 5);
    while (left < right) {
        ll mid = (left + right) / 2;
        if (check(mid)) right = mid;
        else left = mid + 1;
    }
    cout << left << endl;
    return 0;
}
