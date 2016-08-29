#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll N, L1, R1, A, B, C1, C2, M;
ll x, y;
pii gen() {
    ll rx = (A * x + B * y + C1) % M;
    ll ry = (A * y + B * x + C2) % M;
    x = rx; y = ry;
    if (rx > ry) swap(rx, ry);
    return make_pair(rx, ry);
}
const int ENTER = 0;
const int LEAVE = 1;
struct MyEvent {
    int x, type, index;
    MyEvent(int _x, int _t, int _i): x(_x), type(_t), index(_i) {}
};
bool cmp(const MyEvent& a, const MyEvent& that) {
        if (a.x != that.x) {
            return a.x < that.x;
        } else if (a.type != that.type) {
            return a.type < that.type;
        } else {
            return a.index < that.index;
        }
    }
ll get_tot(vector<pii>& arr) {
    ll cur = 0;
    ll pv = -1;
    FOR(j, arr.size()) {
        ll x = arr[j].first, y = arr[j].second;
        if (y <= pv) {
            continue;
        } else if (x > pv) {
            cur += y - x + 1;
            pv = y;
        } else {
            cur += y - pv;
            pv = y;
        }
    }
    return cur;
}
void solve() {
    cin >> N >> L1 >> R1 >> A >> B >> C1 >> C2 >> M;
    vector<pii> arr;
    vector<MyEvent> events;
    x = L1; y = R1;
    arr.push_back({L1, R1});
    for (int i = 1; i < N; ++i) {
        pii nt = gen();
        arr.push_back(nt);
    }
    map<int, set<int> > mp;
    vector<ll> cc(N + 1, 0);
    FOR(i, arr.size()) {
        events.push_back(MyEvent(arr[i].first, ENTER, i));
        events.push_back(MyEvent(arr[i].second, LEAVE, i));
        mp[arr[i].first].insert(i);
        mp[arr[i].second].insert(i);
    }
    sort(arr.begin(), arr.end());
    ll res = get_tot(arr);

    sort(events.begin(), events.end(), cmp);
    ll pv = -1, num = 0;
    set<int> ps;
    FOR(i, events.size()) {
        MyEvent event = events[i];
        if (event.type == ENTER) {
            if (num == 1 && event.x != events[i - 1].x) {
                int ii = *ps.begin();
                cc[ii] += event.x - pv - 1;
                if (mp[pv].size() <= 1 && *(mp[pv].begin()) == ii) ++cc[ii];
            }
            ps.insert(event.index);
            ++num; pv = event.x;
        } else {
            --num;
            if (num == 0) {
                cc[event.index] += max(0ll, event.x - pv - 1);
                if (mp[event.x].size() <= 1) ++cc[event.index];
                if (pv != event.x && mp[pv].size() <= 1 && *(mp[pv].begin()) == event.index) ++cc[event.index];
            }
            ps.erase(event.index);
            pv = event.x;
        }
        assert(ps.size() == num);
    }
    res = res - *max_element(cc.begin(), cc.end());
    cout << res << endl;
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
