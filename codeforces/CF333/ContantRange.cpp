#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int res = 0;
int l = 0, r = 1;
deque<pii> mn, mx;
inline void add(int pos, int val) {
    while (!mx.empty() && (val >= mx.back().first || mx.back().second < l)) mx.pop_back();
    while (!mx.empty() && mx.front().second < l) mx.pop_front();
    mx.push_back({val, pos});
    while (!mn.empty() && (val <= mn.back().first || mn.back().second < l)) mn.pop_back();
    while (!mn.empty() && mn.front().second < l) mn.pop_front();
    mn.push_back({val, pos});
    if (mx.front().first - mn.front().first <= 1) {
        res = max(res, r - l + 1);
    }
}
inline void remove(int pos, int val) {
    while (!mx.empty() && mx.front().second <= pos) mx.pop_front();
    while (!mn.empty() && mn.front().second <= pos) mn.pop_front();
    while (!mx.empty() && mx.back().second <= pos) mx.pop_back();
    while (!mn.empty() && mn.back().second <= pos) mn.pop_back();
    if (mx.front().first - mn.front().first <= 1) {
        res = max(res, r - l - 1);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    FOR(i, n) {
        scanf("%d", &arr[i]);
    }
    add(0, arr[0]);
    while (l < n || r < n) {
        if (l < r && l < n && mx.front().first - mn.front().first > 1) {
            remove(l, arr[l]);
            ++l;
        }
        else if (r < n) {
            add(r, arr[r]);
            ++r;
        }
        else break;
    }
    printf("%d\n", res);
    return 0;
}
