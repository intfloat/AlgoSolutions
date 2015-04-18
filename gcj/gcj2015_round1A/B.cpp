#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int T;
    cin >> T;
    FOR(tt, T) {
        ll barbe, number;
        cin >> barbe >> number;
        vector<ll> tm(barbe);
        FOR(i, barbe) cin >> tm[i];
        cout << "Case #" << tt + 1 << ": ";
        ll left = 1, right = static_cast<ll>(1e15);
        ll mid = -1, cnt = 0;
        while (left < right) {
            mid = (left + right) / 2;            
            cnt = 0;
            FOR(i, barbe) {
                cnt += mid / tm[i];
                if (mid % tm[i]) ++cnt;
            }
            if (cnt > number) right = mid;
            else if (cnt == number) right = mid;
            else if (cnt < number) left = mid + 1;
        }
        cnt = 0;
        FOR(i, barbe){ 
            cnt += (left - 1) / tm[i];
            if ((left - 1) % tm[i]) ++cnt;
        }
        assert(cnt <= number);
        ll res = -1;
        FOR(i, barbe) {
            if ((left - 1) % tm[i] == 0) {
                ++cnt;
                if (cnt == number) { res = i; break; }
            }
        }
        assert(res != -1);
        cout << res + 1 << endl;
    }
    return 0;
}
