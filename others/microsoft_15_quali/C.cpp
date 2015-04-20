#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <string.h>
#include <stdlib.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const ll INF = ~(1ll << 63);
vector<ll> ux, uy, cx, cy;
ll get_cost(const ll x, const ll y) {
    ll res = 0;
    FOR(i, ux.size()) res += (ux[i] - x) * (ux[i] - x);
    FOR(i, uy.size()) res += (uy[i] - y) * (uy[i] - y);
    ll mn = INF;
    assert(cx.size() == cy.size());
    FOR(i, cx.size()) {
        mn = min(mn, abs(x - cx[i]) + abs(y - cy[i]));
    }
    return res + mn;
}

ll solve(vector<ll>& us) {
    ll nuser = us.size();    
    ll sm = accumulate(us.begin(), us.end(), 0);
    ll pos = sm / nuser;
    return pos;
}

int main() {
    ll T, row, col, user, com;    
    cin >> T;    
    FOR(tt, T) {
        cin >> row >> col >> user >> com;
        ux.resize(user); uy.resize(user); cx.resize(com); cy.resize(com);
        FOR(i, user) cin >> ux[i] >> uy[i];
        FOR(i, com) cin >> cx[i] >> cy[i];        
        ll posx = solve(ux);
        ll posy = solve(uy);
        ll cost = INF;
        for (ll i = max(posx - 5, 1ll); i <= min(posx + 5, row); ++i) {
            for (ll j = max(posy - 5, 1ll); j <= min(posy + 5, col); ++j) {
                cost = min(cost, get_cost(i, j));
            }
        }
        cout << "Case #" << tt + 1 << ": " << cost << endl;
    }
    return 0;
}
