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

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second > p2.second;
}

int main() {
    int n;
    while (cin >> n) {
        vector<pair<int, int> > arr;
        int p, d;
        if (n == 0) { cout << 0 << endl; continue; }
        FOR(i, n) {
            cin >> p >> d;
            arr.push_back(make_pair(p, d));
        }
        // in deadline descending order
        sort(arr.begin(), arr.end(), cmp);
        vector<int> hp;
        int ptr = 0;
        int res = 0;
        for (int ddl = arr[0].second; ddl >= 1; --ddl) {
            while (ptr < arr.size() && arr[ptr].second >= ddl) {
                hp.push_back(arr[ptr++].first);
                push_heap(hp.begin(), hp.end());
            }
            if (hp.size() > 0) {
                res += hp[0];
                pop_heap(hp.begin(), hp.end());
                hp.pop_back();
            }
        }
        cout << res << endl;
    }
    return 0;
}
