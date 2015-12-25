#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define ENTER 0
#define LEAVE 1
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, k, l, r;
    scanf("%d %d", &n, &k);
    vector<pii> events;
    FOR(i, n) {
        scanf("%d %d", &l, &r);
        events.push_back({l, ENTER});
        events.push_back({r, LEAVE});
    }
    sort(events.begin(), events.end());
    vector<pii> ans;
    l = -1, r = -1;
    int cnt = 0;
    FOR(i, events.size()) {
        pii& cur = events[i];
        if (cur.second == ENTER) {
            ++cnt;
            if (cnt == k) {
                l = r = cur.first;
            }
            else if (cnt > k) r = cur.first;
            else l = r = -1;
        }
        else {
            --cnt;
            if (cnt >= k) r = cur.first;
            else if (cnt == k - 1) {
                ans.push_back({l, cur.first});
                l = r = -1;
            }
            else {
                l = r = -1;
            }
        }
    }
    printf("%d\n", (int)ans.size());
    FOR(i, ans.size()) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}
