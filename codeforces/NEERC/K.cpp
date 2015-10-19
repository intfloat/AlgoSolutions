#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 100005;
set<pii> tasks[MAX_N];
int main() {
    int n, l, t;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &l, &t);
        tasks[t].insert(make_pair(l, i));
    }
    vector<ll> res(n);
    int ptr = 0, d = (int)sqrt(100000.0) + 3, cnt = 0;
    ll i = 0;
    while (cnt < n) {
        while (tasks[ptr].empty()) ++ptr;
        if (ptr > i) i = ptr;
        int pos = ptr, index = (*tasks[pos].begin()).second;
        ll mn = (*tasks[ptr].begin()).first - (ll)(i - ptr) * (ll)(i - ptr);
        for (int j = ptr + 1; j < ptr + d && j <= i && j < MAX_N; ++j) {
            if (tasks[j].empty()) continue;
            ll cur = (*tasks[j].begin()).first - (ll)(i - j) * (ll)(i - j);
            int nindex = (*tasks[j].begin()).second;
            if (cur < mn || (cur == mn && nindex < index)) {
                mn = cur;
                pos = j;
                index = nindex;
            }
        }
        res[index] = i + (*tasks[pos].begin()).first;
        i = res[index];
        tasks[pos].erase(tasks[pos].begin());
        ++cnt;
    }
    for (int i = 0; i < n; ++i) printf("%I64d ", res[i]);
    printf("\n");
    return 0;
}
