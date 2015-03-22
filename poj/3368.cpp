#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MAX_N = 100005;
vector<vector<int> > rmq(18, vector<int>(MAX_N));
vector<int> numbers(MAX_N);
vector<int> mapping(MAX_N), sm(MAX_N);
int total, cnt;

void rmq_init() {
    for (int i = 1; (1 << i) <= total; ++i) {
        for (int pos = 0; (pos + (1 << i)) <= total; ++pos) {
            rmq[i][pos] = max(rmq[i - 1][pos], rmq[i - 1][pos + (1 << (i - 1))]);
        }
    }
    return;
}

int rmq_query(int left, int right) {
    if (left > right) return -1;
    int len = right - left + 1;
    int i = 0;
    while ((1 << (i + 1)) < len) ++i;
    // assert(i < 17);
    return max(rmq[i][left], rmq[i][right - (1 << i) + 1]);
}

int main() {
    int n, q, low, up;
    while (scanf("%d", &n) != EOF && n) {
        scanf("%d", &q);
        total = 0, cnt = 0;
        FOR(i, n) {
            scanf("%d", &numbers[i]);
            if (i == 0 || numbers[i] == numbers[i - 1]) {
                mapping[i] = total;
                ++cnt;
            }
            else {
                rmq[0][total] = cnt; cnt = 1;
                mapping[i] = ++total;
            }
        }        
        rmq[0][n - 1] = cnt; cnt = 0; ++total;
        sm[0] = rmq[0][0];
        for (int i = 1; i < total; ++i) sm[i] = sm[i - 1] + rmq[0][i];
        rmq_init();
        FOR(i, q) {            
            int low, up;
            scanf("%d %d", &low, &up);            
            --low; --up;
            int ll = mapping[low], rr = mapping[up];
            if (ll == rr) printf("%d\n", up - low + 1);
            else {
                int res = rmq_query(ll + 1, rr - 1);                
                res = max(res, up + 1 - sm[rr - 1]);                
                res = max(res, sm[ll] - (low + 0));
                // assert(res >= 0);
                printf("%d\n", res);
            }
        }
    }
    return 0;
}
