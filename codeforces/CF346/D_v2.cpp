#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
inline int cross(point& a, point& b, point& c) {
    int dx1 = a.first - c.first, dy1 = a.second - c.second;
    int dx2 = b.first - c.first, dy2 = b.second - c.second;
    return dx1 * dy2 - dx2 * dy1;
}
int n;
vector<point> arr;
int main() {
    int res = 0;
    scanf("%d", &n);
    arr.resize(n + 1);
    FOR(i, n + 1) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    arr.pop_back();
    FOR(i, n) {
        point& a = arr[(i - 1 + n) % n];
        point& b = arr[i % n];
        point& c = arr[(i + 1) % n];
        res += (cross(c, a, b) > 0);
    }
    printf("%d\n", res);
    return 0;
}
