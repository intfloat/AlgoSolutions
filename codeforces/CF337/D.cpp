#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct Node {
    int key, l, r;
    Node(int _k, int _l, int _r): key(_k), l(_l), r(_r) {}
};
bool cmp(const Node& a, const Node& b) {
    if (a.l != b.l) return a.l < b.l;
    else return a.r < b.r;
}
map<int, vector<Node> > xs, ys;
set<int> st;
map<int, int> mp;
inline void build() {
    int cnt = 1;
    for (auto it = st.begin(); it != st.end(); ++it) {
        mp[*it] = cnt++;
    }
}
ll res = 0;
inline void smerge(map<int, vector<Node> >& ss) {
    for (auto it = ss.begin(); it != ss.end(); ++it) {
        vector<Node> arr = it->second;
        vector<Node>& ori = it->second;
        ori.clear();
        sort(arr.begin(), arr.end(), cmp);
        FOR(i, arr.size()) {
            if (ori.empty()) ori.push_back(arr[i]);
            else if (arr[i].l > ori.back().r) ori.push_back(arr[i]);
            else ori.back().r = max(ori.back().r, arr[i].r);
        }
        FOR(i, ori.size()) {
            res += ori[i].r - ori[i].l + 1;
        }
    }
}
const int MAX_N = 100005 * 4;
typedef int E;
E f[MAX_N];
int N;
inline void update(int pos, E val) {
    if (pos == 0) return;
    while (pos <= N) {
        f[pos] += val;
        pos += pos & (-pos);
    }
}
inline E query(int pos) {
    E ret = 0;
    while (pos > 0) {
        ret += f[pos];
        pos -= pos & (-pos);
    }
    return ret;
}
inline int change(int num) {
    return mp[num];
}
#define ENTER 0
#define LEAVE 1
typedef pair<pii, int> piii;
map<int, int> cc;
int main() {
    int n, x1, x2, y1, y2;
    scanf("%d", &n);
    FOR(i, n) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (x1 == x2) xs[x1].push_back(Node(x1, y1, y2));
        else ys[y1].push_back(Node(y1, x1, x2));
        st.insert(x1); st.insert(x2); st.insert(y1); st.insert(y2);
    }
    build();
    smerge(xs); smerge(ys);
    N = st.size() + 5;
    memset(f, 0, sizeof f);
    vector<piii> events;
    for (auto it = ys.begin(); it != ys.end(); ++it) {
        vector<Node>& arr = it->second;
        FOR(i, arr.size()) {
            Node& cur = arr[i];
            events.push_back({{cur.l, ENTER}, cur.key});
            events.push_back({{cur.r, LEAVE}, cur.key});
        }
    }
    sort(events.begin(), events.end());
    int ptr = 0;
    for (auto it = xs.begin(); it != xs.end(); ++it) {
        int pos = it->first;
        vector<Node>& arr = it->second;
        while (ptr < (int)events.size() && pos >= events[ptr].first.first) {
            int xpos = events[ptr].first.first, ypos = events[ptr].second;
            int type = events[ptr].first.second;
            if (pos > xpos) {
                if (type == ENTER) {
                    ++cc[ypos];
                    if (cc[ypos] == 1) update(change(ypos), 1);
                }
                else {
                    // assert(type == LEAVE);
                    --cc[ypos];
                    if (cc[ypos] == 0) update(change(ypos), -1);
                }
                ++ptr;
            }
            else if (pos == xpos && type == ENTER) {
                ++cc[ypos];
                if (cc[ypos] == 1) update(change(ypos), 1);
                ++ptr;
            }
            else break;
        }
        FOR(i, arr.size()) {
            Node& cur = arr[i];
            int low = change(cur.l), up = change(cur.r);
            res -= query(up) - query(low - 1);
        }
    }
    cout << res << endl;
    return 0;
}
