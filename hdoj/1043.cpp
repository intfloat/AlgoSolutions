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
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

struct Node {
    int g, h;
    string state;
    bool operator<(const Node that) const {
        return (this->h) > (that.h);
    }
    Node(int _g, int _h, string _s): g(_g), h(_h), state(_s) {}
};

const string goal = "123456789";
const string no_sol = "unsolvable";
const string dir = "rlud";
const int dir_x[] = {0, 0, -1, 1};
const int dir_y[] = {1, -1, 0, 0};
map<string, string> pre;
map<string, char> action;
map<string, int> cost;
priority_queue<Node> q;
string start;

int get_h(const string& st) {    
    int ret = 0;
    FOR(i, st.size()) {
        if (st[i] == '9') continue;
        int r = i / 3, c = i % 3;
        int dr = (st[i] - '1') / 3, dc = (st[i] - '1') % 3;
        ret += abs(r - dr) + abs(c - dc);
    }
    return ret;
}

pair<int, int> get_pos(const string& st) {
    FOR(i, st.size()) {
        if (st[i] == '9') return make_pair(i / 3, i % 3);
    }
    // assert(false);
    // return NULL;
}

bool check(const string& st) {
    int ret = 0;
    for (int i = 0; i < st.size(); ++i)
    for (int j = i + 1; j < st.size(); ++j)
        ret += (st[i] > st[j] && st[i] != '9' && st[j] != '9');
    // cout << ret << endl;
    return (ret % 2 == 0);
}

void debug(const string& st) {
    cout << endl;
    FOR(i, 3) {
        FOR(j, 3) {
            if (st[i * 3 + j] == '9') cout << 'x';
            else cout << st[i * 3 +j];
        }
        cout << endl;
    }
}

int main() {
    // int start = 0;
    char s[100];
    while (gets(s) != NULL) {
        string t(s);
        pre.clear(); action.clear(); cost.clear();
        while (!q.empty()) q.pop();
        start = "";
        FOR(i, t.size()) {
            // cin >> t;
            if (t[i] == 'x') start += '9';
            else if (t[i] >= '1' && t[i] <= '8' ) start += t[i];
        }
        if (!check(start)) {
            cout << no_sol << endl;
            continue;
        }
        q.push(Node(0, get_h(start), start));
        pre[start] = start; action[start] = '\0'; cost[start] = get_h(start);
        bool ok = false;
        while (!q.empty()) {
            Node tp = q.top(); q.pop();
            // if (cost[tp.state] < tp.g + tp.h) continue;
            // cout << tp.state << " " << tp.g + tp.h << endl;
            // reach goal state
            if (tp.state == goal) {
                ok = true;
                string cur = goal;
                string res = "";
                // debug(cur);
                while (cur != start) {
                    res = action[cur] + res;
                    cur = pre[cur];
                    // debug(cur);
                }
                cout << res << endl;
                break;
            }
            pair<int, int> pos = get_pos(tp.state);
            int x = pos.first, y = pos.second;
            FOR(i, 4) {
                int nx = x + dir_x[i];
                int ny = y + dir_y[i];
                if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
                string nst = tp.state;                
                swap(nst[x * 3 + y], nst[nx * 3 + ny]);
                // ++nst.g; 
                // nst.h = get_h(nst.state);
                Node node(tp.g + 1, get_h(nst), nst);
                if (pre.find(nst) == pre.end() 
                //    || cost[nst] > node.g + node.h
                    ) {
                    q.push(node);
                    pre[nst] = tp.state; action[nst] = dir[i]; cost[nst] = node.g + node.h;
                }
            }
        }
        if (!ok) cout << no_sol << endl;
    }
    return 0;
}



