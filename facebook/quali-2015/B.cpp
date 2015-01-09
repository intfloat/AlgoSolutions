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

int main() {
    int T, P, C, F, N;
    cin >> T;
    FOR(tt, T) {
        cout << "Case #" << tt + 1 << ": ";
        bool ok = false;
        cin >> P >> C >> F;
        tuple<int, int, int> goal = make_tuple(P, C, F);
        cin >> N;
        vector<tuple<int, int, int> > v;
        FOR(i, N) {
            cin >> P >> C >> F;
            v.push_back(make_tuple(P, C, F));
        }
        FOR(i, 1 << N) {
            tuple<int, int, int> cur = make_tuple(0, 0, 0);
            for (int j = 0; j < N; ++j) {
                if ((1<<j)&i) {
                    get<0>(cur) += get<0>(v[j]);
                    get<1>(cur) += get<1>(v[j]);
                    get<2>(cur) += get<2>(v[j]);
                }
            }
            if (cur == goal) { ok = true; break; }
        }
        if (ok) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
