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
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MOD = 1000000007;
typedef long long ll;
class BIT {
public:
    vector<int> sum, idx;
    BIT() { idx.push_back(-1); }

    void adjust() {
        this->sum.resize(idx.size());
        fill(sum.begin(), sum.end(), 0);
    }

    // find the rightmost position whose value is <= val
    int binary_search(int val) {
        int left = 0, right = idx.size() - 1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (idx[mid] == val) return mid;
            else if (idx[mid] > val) right = mid - 1;
            else left = mid;
        }
        if (idx[right] <= val) return right;
        return left;
    }

    void add(int pos, const int val) {
        pos = this->binary_search(pos);
        assert(pos > 0);
        while (pos < this->sum.size()) {
            this->sum[pos] = (this->sum[pos] + val) % MOD;
            pos += pos & (-pos);
        }
        return;
    }

    int query(int pos) {
        int res = 0;
        pos = this->binary_search(pos);
        while (pos > 0) {
            res = (res + this->sum[pos]) % MOD;
            pos -= pos & (-pos);
        }
        return res;
    }
};

int main() {
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    int row, col, K;
    scanf("%d %d %d", &row, &col, &K);
    vector<vector<int> > arr(row, vector<int>(col));
    FOR(i, row) FOR(j, col) { 
        scanf("%d", &arr[i][j]); 
        --arr[i][j]; 
    }    
    vector<BIT> ctree(K);
    ctree[arr[0][0]].idx.push_back(0);
    for (int j = 1; j <= col -2; ++j)
        for (int i = 1; i <= row - 2; ++i) {
        int color = arr[i][j];
        if (ctree[color].idx.back() != j)
            ctree[color].idx.push_back(j);
    }
    FOR(i, K) ctree[i].adjust();
    BIT full;
    for (int i = 0; i <= col - 2; ++i) full.idx.push_back(i);
    full.adjust();

    full.add(0, 1); ctree[arr[0][0]].add(0, 1);    
    // ignore first row & first column & last row & last column
    for (int r = 1; r <= row - 2; ++r) {
        for (int c = col - 2; c > 0; --c) {            
            int color = arr[r][c];
            ll prev = ((ll)full.query(c - 1) - ctree[color].query(c - 1) + MOD) % MOD;
            assert(prev >= 0);
            ctree[color].add(c, prev);
            full.add(c, prev);
        }
    }
    int color = arr[row - 1][col - 1];
    ll res = ((ll)full.query(col - 2) - ctree[color].query(col - 2) + MOD) % MOD;
    printf("%lld\n", res);
    return 0;
}
