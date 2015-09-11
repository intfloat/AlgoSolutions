#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> pii;
bool cmp(const pii& a, const pii& b) {
    int x1 = get<0>(a) / 1000, x2 = get<0>(b) / 1000;
    if (x1 != x2) return x1 < x2;
    int y1 = get<1>(a), y2 = get<1>(b);
    if (y1 != y2 && x1 % 2 == 0) return y1 < y2;
    else if (y1 != y2) return y1 > y2;
    return get<2>(a) < get<2>(b);
}
int main() {
    int n, x, y;
    scanf("%d", &n);
    vector<pii> arr;
    FOR(i, n) {
        scanf("%d %d", &x, &y);
        arr.push_back(make_tuple(x, y, i + 1));
    }
    sort(arr.begin(), arr.end(), cmp);
    FOR(i, n) {
        printf("%d ", get<2>(arr[i]));
    }
    return 0;
}
