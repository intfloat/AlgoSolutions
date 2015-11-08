#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
struct Node {
    vector<ll> ip;
    ll cnt, rep;
    Node() {
        ip.resize(4);
    }
    void norm() {
        ll rem = cnt;
        rep = 0;
        FOR(i, 4) {
            if (rem >= 8) {
                rem -= 8;
            }
            else if (rem == 0) {
                ip[i] = 0;
            }
            else {
                ll del = 8 - rem;
                ll tt = ~((1 << del) - 1);
                ip[i] = (tt & ip[i]);
                rem = 0;
            }
            rep += ip[i] * (1 << (24 - 8 * i));
        }
    }
    ll mx() {
        return rep + ((1ll << (32 - cnt)) - 1);
    }
    ll mn() { return rep; }
};
bool cmp(const Node& a, const Node& b) {
    FOR(i, 4) {
        if (a.ip[i] < b.ip[i]) return true;
        else if (a.ip[i] > b.ip[i]) return false;
    }
    return a.cnt < b.cnt;
}
bool check(Node& a, Node& b) {
    return (a.mx() >= b.mx() && a.mn() <= b.mn());
}
void solve() {
    ll N;
    cin >> N;
    vector<Node> arr(N);
    FOR(i, N) {
        char tmp;
        FOR(j, 4) {
            cin >> arr[i].ip[j] >> tmp;
        }
        cin >> arr[i].cnt;
        arr[i].norm();
    }
    sort(arr.begin(), arr.end(), cmp);
    ll ptr = 0;
    vector<Node> res;
    while (ptr < N) {
        ll i = ptr + 1;
        while (i < N && check(arr[ptr], arr[i])) ++i;
        res.push_back(arr[ptr]);
        ptr = i;
    }
    vector<Node> ans;
    while (true) {
        ans.clear();
        ans.push_back(res[0]);
        int ptr = 1;
        while (ptr < (int)res.size()) {
            if (res[ptr].cnt == res[ptr - 1].cnt && res[ptr - 1].mx() + 1 == res[ptr].mn()) {
                ll tmp = (1ll << (32 - res[ptr - 1].cnt));
                if (res[ptr - 1].mn() & tmp) {
                    ans.push_back(res[ptr++]);
                    continue;
                }
                --ans.back().cnt; ans.back().norm();
                if (ptr + 1 < (int)res.size()) ans.push_back(res[ptr + 1]);
                ptr += 2;
            }
            else {
                ans.push_back(res[ptr]);
                ++ptr;
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        if (ans.size() == res.size()) break;
        res = ans;
    }
    arr = ans;
    FOR(ptr, arr.size()) {
        cout << arr[ptr].ip[0] << "." << arr[ptr].ip[1] << "."
            << arr[ptr].ip[2] << "." << arr[ptr].ip[3]
            << "/" << arr[ptr].cnt << endl;
    }
    return;
}
int main() {
    ll TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ":" << endl;
        solve();
    }
    return 0;
}
