#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct Node {
    int idx, t, d;
    Node(int _i, int _t, int _d): idx(_i), t(_t), d(_d) {}
};
int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    ll cur = 0, finish = 0;
    int idx = -1;
    vector<ll> res(n, -1);
    queue<Node> tasks;
    for (int i = 0; i < n; ++i) {
        ll start, duration;
        cin >> start >> duration;
        while (true) {
            if (idx < 0 && tasks.empty()) {
                cur = start;
                finish = cur + duration;
                idx = i;
                res[idx] = finish;
                break;
            }
            else if (idx < 0 && !tasks.empty()) {
                finish = cur + tasks.front().d;
                idx = tasks.front().idx;
                res[idx] = finish;
                tasks.pop();
            }
            else if (idx >= 0 && finish <= start) {
                cur = finish;
                idx = -1;
            }
            else if (idx >= 0 && finish > start) {
                if (static_cast<int>(tasks.size()) >= b) {
                    res[i] = -1;
                    break;
                }
                else {
                    tasks.push(Node(i, start, duration));
                    cur = start;
                    break;
                }
            }
        }
    }
    while (idx >= 0 || !tasks.empty()) {
        if (idx >= 0) {
            cur = finish;
            idx = -1;
        }
        else {
            finish = cur + tasks.front().d;
            idx = tasks.front().idx;
            res[idx] = finish;
            tasks.pop();
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%I64d ", res[i]);
    }
    printf("\n");
    return 0;
}
