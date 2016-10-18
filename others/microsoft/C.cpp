#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct Event {
    int timestamp, sid, idx;
    Event(int _t, int _s, int _i): timestamp(_t), sid(_s), idx(_i) {}
};
vector<int> ids(10005);
bool operator<(const Event& a, const Event& b) {
    if (a.timestamp != b.timestamp) {
        return a.timestamp > b.timestamp;
    } else {
        return ids[a.sid] > ids[b.sid];
    }
}
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> avail(m + 1, 0);
    priority_queue<Event> pq;
    vector<vector<pii> > offices(n);
    FOR(i, n) {
        int t, p, oid, w;
        scanf("%d %d %d", &ids[i], &t, &p);
        pq.push(Event(t, i, 0));
        offices[i].push_back({0, 0});
        FOR(j, p) {
            scanf("%d %d", &oid, &w);
            offices[i].push_back({oid, w});
        }
    }
    vector<int> res(n);
    while (!pq.empty()) {
        Event tp = pq.top(); pq.pop();
        int timestamp = tp.timestamp, sid = tp.sid, idx = tp.idx;
        if (idx + 1 == (int)offices[sid].size()) {
            res[sid] = timestamp;
        } else {
            int nt_off = offices[sid][idx + 1].first;
            int nt_time = timestamp + k;
            nt_time = max(nt_time, avail[nt_off]) + offices[sid][idx + 1].second;
            avail[nt_off] = nt_time;
            pq.push(Event(nt_time, sid, idx + 1));
        }
    }
    FOR(i, n) {
        printf("%d\n", res[i]);
    }
    return 0;
}
