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

#define FORWARD true
#define BACKWARD false

const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};

void change(string& s) {
    vector<string> v;
    FOR(i, 4) v.push_back(s.substr(i * 2, 2));
    sort(v.begin(), v.end());
    s.clear();
    FOR(i, 4) s += v[i];    
}

int main() {
    char line[100];
    while (gets(line) != NULL) {
        string s(line);
        string start, goal;
        FOR(i, s.size()) {
            if (s[i] >= '1' && s[i] <= '8') start += s[i];
        }
        gets(line);
        s = line;
        FOR(i, s.size()) {
            if (s[i] >= '1' && s[i] <= '8') goal += s[i];
        }
        change(start); change(goal);
        if (start == goal) { cout << "YES" << endl; continue; }

        
        map<string, bool> dir;
        map<string, int> cost;
        queue<string> q;
        q.push(start); q.push(goal);
        dir[start] = FORWARD; dir[goal] = BACKWARD;
        cost[start] = cost[goal] = 0;        

        bool ok = false;
        while (!q.empty() && !ok) {
            string tp = q.front(); q.pop();
            // cout << tp << endl;
            if (cost[tp] >= 4) continue;
            set<pair<int, int> > points;
            for (int i = 0; i < tp.size(); i += 2) points.insert(make_pair(tp[i] - '0', tp[i + 1] - '0'));
            assert(points.size() == 4);
            int j = 0;
            for (set<pair<int, int> >::iterator it = points.begin(); it != points.end(); ++it, ++j) {
                int x = (*it).first, y = (*it).second;
                FOR(i, 4) {
                    int nx = x + dir_x[i], ny = y + dir_y[i];                    
                    if (nx < 1 || nx > 8 || ny < 1 || ny > 8) continue;
                    if (points.find(make_pair(nx, ny)) != points.end()) {
                        nx += dir_x[i]; ny += dir_y[i];
                        if (nx < 1 || nx > 8 || ny < 1 || ny > 8) continue;
                        if (points.find(make_pair(nx, ny)) != points.end()) continue;
                    }
                    string state = tp;
                    state[j * 2] = nx + '0';
                    state[j * 2 + 1] = ny + '0';
                    change(state);
                    if (dir.find(state) == dir.end()) {
                        q.push(state);
                        dir[state] = dir[tp];
                        cost[state] = cost[tp] + 1;
                    }
                    else if (dir[state] != dir[tp]) {
                        assert(cost[state] + cost[tp] <= 8);
                        // cout << "step: "<< cost[state] + cost[tp] << endl;
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
