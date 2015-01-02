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

const int center[] = {6, 7, 8, 11, 12, 15, 16, 17};
const int block[4][7] = {{0,2,6,11,15,20,22},{1,3,8,12,17,21,23},{4,5,6,7,8,9,10},{13,14,15,16,17,18,19}};
const string action = "AFBEHCGD";
vector<char> res;

int get_h(const string& s) {
    vector<int> cnt(3, 0);
    FOR(i, 8) ++cnt[s[center[i]] - '1'];
    return 8 - *max_element(cnt.begin(), cnt.end());
}

void change(string& s, int pos, bool rev) {
    if (!rev) {
        char t = s[block[pos][0]];
        for (int i = 0; i < 6; ++i) s[block[pos][i]] = s[block[pos][i + 1]];
        s[block[pos][6]] = t;
    }
    else {
        char t = s[block[pos][6]];
        for (int i = 6; i >= 1; --i) s[block[pos][i]] = s[block[pos][i - 1]];
        s[block[pos][0]] = t;
    }
    return;
}

const int seq[] = {0, 1, 2, 3, 1, 0, 3, 2};
const bool label[] = {false, false, true, true, true, true, false, false};
bool IDAstar(string cur, int dep, int mx) {
    int f = dep + get_h(cur);
    if (f > mx) return false;
    // cout << cur << endl;
    if (get_h(cur) == 0) {
        FOR(i, res.size()) cout << res[i];
        cout << endl;
        cout << cur[center[0]] << endl;
        return true;
    }
    FOR(i, 8) {
        string state = cur;
        change(state, seq[i], label[i]);
        res.push_back(action[seq[i] * 2 + label[i]]);
        if (IDAstar(state, dep + 1, mx)) return true;
        res.pop_back();
    }
    return false;
}

int main() {
    char line[100];
    while (gets(line) != NULL) {        
        string t(line);
        string start;
        FOR(i, t.size()) {
            if (t[i] >= '0' && t[i] <= '3') start += t[i];
        }
        if (start[0] == '0') return 0;
        int low = get_h(start);
        if (low == 0) {
            cout << "No moves needed" << endl;
            cout << start[center[0]] << endl;
            continue;
        }
        for (int i = low; ; ++i) {
            res.clear();
            if (IDAstar(start, 0, i)) break;            
        }
    }
    return 0;
}
