#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
const char* FIRST = "Laurence";
const char* SECOND = "Seymour";
bool lose(ll num);
bool win(ll num);
vector<ll> factors;
inline bool isprime(int num) {
    assert(num >= 2);
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}
inline bool gprime(ll num) {
    int cnt = 0;
    while (num > 0) {
        cnt += (num % 10);
        num /= 10;
    }
    return ((cnt == 1) || isprime(cnt));
}
bool lose(ll num) {
    if (gprime(num)) return true;
    FOR(i, factors.size()) {
        if (num % factors[i] == 0) {
            ll tmp = num;
            while (tmp % factors[i] == 0) tmp /= factors[i];
            if (!win(tmp)) return false;
        }
    }
    return true;
}
bool win(ll num) {
    if (gprime(num)) return false;
    FOR(i, factors.size()) {
        if (num % factors[i] == 0) {
            ll tmp = num;
            while (tmp % factors[i] == 0) tmp /= factors[i];
            if (lose(tmp)) return true;
        }
    }
    return false;
}
void solve() {
    ll n;
    cin >> n;
    factors.clear();
    ll tmp = n;
    for (ll i = 2; i * i <= tmp; ++i) {
        if (tmp % i == 0) {
            factors.push_back(i);
            while (tmp % i == 0) tmp /= i;
        }
    }
    if (tmp > 1) factors.push_back(tmp);
    if (win(n)) printf("%s\n", FIRST);
    else printf("%s\n", SECOND);
    return;
}
int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ": ";
        solve();
    }
    return 0;
}
