#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> point;
inline ll cross(point& a, point& b, point& c) {
    ll x1 = a.first - c.first, x2 = b.first - c.first;
    ll y1 = a.second - c.second, y2 = b.second - c.second;
    return x1 * y2 - x2 * y1;
}
int main() {
    int N;
    scanf("%d", &N);
    vector<point> arr;
    ll x, y;
    FOR(i, N) {
        scanf("%lld %lld", &x, &y);
        arr.push_back(make_pair(x, y));
    }
    arr.push_back(arr[0]);
    ll area = 0;
    point origin = make_pair(0ll, 0ll);
    for (int i = 1; i <= N; ++i) {
        area += cross(arr[i - 1], arr[i], origin);
    }
    area = max(area, -area) / 2;
    ll cnt = N;
    for (int i = 1; i <= N; ++i) {
        ll dx = abs(arr[i].first - arr[i - 1].first);
        ll dy = abs(arr[i].second - arr[i - 1].second);
        cnt += __gcd(dx, dy) - 1;
    }
    ll res = area + 1 - cnt / 2;
    printf("%lld\n", res);
    return 0;
}
