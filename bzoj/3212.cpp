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

typedef long long ll;
const int MAX_N = 100005;
ll mul[MAX_N], add[MAX_N];

void update_aux(int idx, ll mul_num, ll add_num) {
    for (int i = idx; i < MAX_N; i += (i & (-i))) {
        mul[i] += mul_num;
        add[i] += add_num;
    }
    return;
}

void update(int left, int right, ll inc) {
    update_aux(left, inc, -left * inc + inc);
    update_aux(right, -inc, right * inc);
}

ll query_sum_aux(int idx) {
    ll mul_res = 0, add_res = 0;
    for (int i = idx; i > 0; i -= (i & (-i))) {
        mul_res += mul[i];
        add_res += add[i];
    }
    return idx * mul_res + add_res;    
}

ll query_sum(int left, int right) {    
    return query_sum_aux(right) - query_sum_aux(left - 1);
}

int main() {
    int N, Q, t;
    scanf("%d %d", &N, &Q);
    memset(mul, 0, sizeof(mul));
    memset(add, 0, sizeof(add));
    FOR(i, N) {
        scanf("%d", &t);
        update_aux(i + 1, 0, t);
    }
    FOR(i, Q) {
        char type;
        int a, b, c;
        scanf(" %c", &type);
        if (type == 'C') {
            scanf("%d %d %d", &a, &b, &c);
            update(a, b, c);
        }
        else if (type == 'Q') {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query_sum(a, b));
        }
    }
    return 0;
}
