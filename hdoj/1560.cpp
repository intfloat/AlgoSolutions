// Got TimeLimitExceeded.... WTF...
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

string dna[8];
int n, ptr[8];

int get_h() {
    int res = 0;
    FOR(i, n) res = max(res, (int)dna[i].size() - ptr[i]);
    return res;
}

bool IDAstar(int g, int d) {
    // cout << state << " " << g << " " << d << endl;
    int h = get_h();
    if (h == 0) return true;
    if (g + h > d) return false;
    int tmp[8];
    FOR(i, n) tmp[i] = ptr[i];
    set<char> cand;
    FOR(i, n) {
        if (ptr[i] < dna[i].size()) cand.insert(dna[i][ptr[i]]);
    }
    for (set<char>::iterator it = cand.begin(); it != cand.end(); ++it) {
        FOR(i, n) if (ptr[i] < dna[i].size() && dna[i][ptr[i]] == *it) ++ptr[i];
        if (IDAstar(g + 1, d)) return true;
        FOR(i, n) ptr[i] = tmp[i];
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    FOR(tt, T) {
        cin >> n;
        memset(ptr, 0, sizeof(ptr));
        FOR(i, n) cin >> dna[i];
        int low = get_h();
        for (int d = low; ; ++d) {
            // cout << d << endl;
            memset(ptr, 0, sizeof(ptr));
            if (IDAstar(0, d)) { cout << d << endl; break; }
        }
    }
    return 0;
}
