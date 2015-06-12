#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class ColorfulLineGraphs {
public:
    int countWays(long long, long long, int);
};

typedef long long ll;
ll MOD;
ll pw(ll number, ll p) {
    if (p == 0) return 1;
    if (p == 1) return number;
    ll t = pw(number, p / 2);
    t = (t * t) % MOD;
    if (p % 2) t = (t * number) % MOD;
    return t;
}

int ColorfulLineGraphs::countWays(long long N, long long K, int M) {
    ll res = 1;
    MOD = M;
    K = K % M;
    for (ll i = 1; i <= M; ++i) {
        res = (res * (K + i * K - i)) % M;
    }
    res = pw(res, (N - 1) / M);
    ll up = (N - 1) % M;
    for (ll i = 1; i <= up; ++i) {
        res = (res * (K + i * K - i)) % M;
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
