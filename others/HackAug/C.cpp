#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
struct Node {
    bool point, leave;
    int x, y1, y2;
    bool operator<(const Node& that) const {
        if (x != that.x) return x < that.x;
        if (point && !that.point) {
            if (!that.leave) return false;
            else return true;
        }
        if (!point && that.point) {
            if (!leave) return true;
            else return false;
        }
        if (!point && !that.point) {
            if (!leave && that.leave) return true;
            if (leave && !that.leave) return false;
        }
        return false;
    }
    Node(bool p, int _x, int _y1, int _y2, bool _l): point(p), x(_x), y1(_y1), y2(_y2), leave(_l) {}
};
const int MAX_N = 300005;
int f[MAX_N], N;
void update(int pos, int val){
    if(pos == 0) return;
    while(pos <= N){
        f[pos] += val;
        pos += pos&(-pos);
    }
}
int query(int pos){
    int sum = 0;
    while(pos > 0){
        sum += f[pos];
        pos -= pos&(-pos);
    }
    return sum;
}
int main() {
    int n, m, l, x, y;
    scanf("%d %d %d", &n, &m, &l);
    vector<Node> arr;
    vector<int> ys;
    FOR(i, n) {
        scanf("%d %d", &x, &y);
        ys.push_back(y);
        ys.push_back(y + l);
        arr.push_back(Node(false, x, y, y + l, false));
        arr.push_back(Node(false, x + l, y, y + l, true));
    }
    FOR(i, m) {
        scanf("%d %d", &x, &y);
        ys.push_back(y);
        arr.push_back(Node(true, x, y, -1, false));
    }
    sort(ys.begin(), ys.end());
    int sz = unique(ys.begin(), ys.end()) - ys.begin();
    N = sz + 5;
    ys.resize(sz);
    map<int, int> mp;
    int cnt = 1;
    FOR(i, ys.size()) {
        mp[ys[i]] = cnt++;
    }
    sort(arr.begin(), arr.end());
    memset(f, 0, sizeof f);
    int res = 0;
    FOR(i, arr.size()) {
        if (!arr[i].point && !arr[i].leave) {
            update(mp[arr[i].y1], 1);
            update(mp[arr[i].y2] + 1, -1);
        }
        else if (!arr[i].point && arr[i].leave) {
            update(mp[arr[i].y1], -1);
            update(mp[arr[i].y2] + 1, 1);
        }
        else {
            int cur = query(mp[arr[i].y1]);
            res = max(cur, res);
        }
    }
    printf("%d\n", res);
    return 0;
}
