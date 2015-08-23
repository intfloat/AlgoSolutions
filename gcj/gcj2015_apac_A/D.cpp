#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
typedef pair<int, char> rec;
const int dir_x[] = {1, 0, -1, 0};
const int dir_y[] = {0, -1, 0, 1};
set<point> eat;
inline bool has_food(point& pos) {
    int cc = pos.first + pos.second;
    if (cc % 2 == 0) return false;
    if (eat.find(pos) != eat.end()) return false;
    return true;
}
inline void eat_food(point& pos) {
    eat.insert(pos);
}
void solve() {
    int Q, row, col;
    cin >> Q >> row >> col;
    deque<point> snake;
    eat.clear();
    int d = 3, ptr = 0;
    vector<rec> cmd(Q);
    FOR(i, Q) cin >> cmd[i].first >> cmd[i].second;
    sort(cmd.begin(), cmd.end());
    map<point, int> visited;
    snake.push_back({0, 0});
    visited[{0, 0}] = 1;
    int tt = 1;
    while (true) {
        if (tt > 1500000) {
            cout << snake.size() << endl;
            return;
        }
        point tp = snake.front();
        tp.first = (tp.first + dir_x[d] + row) % row;
        tp.second = (tp.second + dir_y[d] + col) % col;
        if (!has_food(tp)) {
            --visited[snake.back()];
            if (visited[snake.back()] == 0) visited.erase(snake.back());
            ++visited[tp];
            if (visited[tp] >= 2) {
                cout << snake.size() << endl;
                return;
            }
            snake.push_front(tp);
            snake.pop_back();
        }
        else {
            eat_food(tp);
            ++visited[tp];
            if (visited[tp] >= 2) {
                cout << snake.size() << endl;
                return;
            }
            snake.push_front(tp);
        }
        if (ptr < cmd.size() && cmd[ptr].first == tt) {
            if (cmd[ptr].second == 'L') d = (d - 1 + 4) % 4;
            else {
                d = (d + 1) % 4;
                assert(cmd[ptr].second == 'R');
            }
            ++ptr;
        }
        ++tt; // increase clock
    }
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
