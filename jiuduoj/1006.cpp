#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int zidx = -1, jidx = -1;
        int zcnt = 0, jcnt = 0;
        FOR(i, s.size()) {
            if (s[i] == 'z') { zidx = i; ++zcnt; }
            if (s[i] == 'j') { jidx = i; ++jcnt; }
        }
        if (zcnt != 1 || jcnt != 1 || zidx > jidx) {
            cout << "Wrong Answer" << endl;
            continue;
        }
        int mid = jidx - zidx - 1;
        if (mid == 0) {
            cout << "Wrong Answer" << endl;
            continue;   
        }
        int prev = zidx, after = s.size() - jidx - 1;
        bool ok = true;
        FOR(i, mid - 1) {
            prev <<= 1;
            if (prev > after) { ok = false; break; }
        }
        if (prev == after && ok)
            cout << "Accepted" << endl;
        else cout << "Wrong Answer" << endl;
    }
    return 0;
}
