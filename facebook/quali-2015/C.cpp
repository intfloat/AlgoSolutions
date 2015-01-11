#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#include <tuple>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int dir_x[] = {0, -1, 0, 1};
const int dir_y[] = {-1, 0, 1, 0};
const char dir[] = {'<', '^', '>', 'v'};

int get_index(const char d) {
    FOR(i, 4) if (dir[i] == d) return i;
    return -1;
}

int main() {
    int T, row, col;
    pair<int, int> start, goal;
    cin >> T;
    FOR(tt, T) {
        cout << "Case #" << tt + 1 << ": ";
        cin >> row >> col;
        vector<string> maze;
        FOR(i, row) {
            string t;
            cin >> t;
            maze.emplace_back(t);
        }
        FOR(i, row) FOR(j, col) {
            if (maze[i][j] == 'S') { start = {i, j}; maze[i][j] = '.'; }
            if (maze[i][j] == 'G') { goal = {i, j}; maze[i][j] = '.'; }
        }
        set<tuple<int, int, int> > danger;
        FOR(i, row) FOR(j, col) {
            int ind = get_index(maze[i][j]);
            if (ind < 0) continue;
            FOR(k, 4) {
                int pos = (k + ind) % 4;
                int curx = i, cury = j;
                while (true) {
                    curx += dir_x[pos]; cury += dir_y[pos];
                    // out of boundary
                    if (curx < 0 || curx >= row || cury < 0 || cury >= col) break;
                    // wall
                    if (maze[curx][cury] == '#') break;
                    // laser
                    if (get_index(maze[curx][cury]) >= 0) break;
                    danger.insert(make_tuple(curx, cury, k));
                }
            }
        }
        bool ok = false;
        queue<tuple<int, int, int> > q;
        map<tuple<int, int, int>, int> res;
        auto ft = make_tuple(start.first, start.second, 0);
        q.push(ft); res[ft] = 0;
        int step;
        while (!q.empty()) {
            auto tp = q.front(); q.pop();
            int x = get<0>(tp), y = get<1>(tp), rem = get<2>(tp);
            if (make_pair(x, y) == goal) { ok = true; step = res[tp]; break; }
            int nrem = (rem + 1) % 4;
            FOR(i, 4) {
                int nx = x + dir_x[i], ny = y + dir_y[i];
                auto cand = make_tuple(nx, ny, nrem);
                if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                if (maze[nx][ny] == '#') continue;
                if (get_index(maze[nx][ny]) >= 0) continue;
                if (danger.find(cand) != danger.end()) continue;
                if (res.find(cand) != res.end() && res[tp] + 1 >= res[cand]) continue;
                q.push(cand); res[cand] = res[tp] + 1;
            }
        }
        if (ok) cout << step << endl;
        else cout << "impossible" << endl;
    }
    return 0;
}
